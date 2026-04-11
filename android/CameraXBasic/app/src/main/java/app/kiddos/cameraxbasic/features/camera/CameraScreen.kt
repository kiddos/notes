package app.kiddos.cameraxbasic.features.camera

import android.content.Context
import android.graphics.Bitmap
import android.graphics.Matrix
import android.hardware.camera2.CaptureRequest
import android.util.Log
import android.util.Size
import android.view.ViewGroup.LayoutParams.MATCH_PARENT
import android.widget.LinearLayout
import androidx.camera.camera2.interop.Camera2CameraControl
import androidx.camera.camera2.interop.CaptureRequestOptions
import androidx.camera.camera2.interop.ExperimentalCamera2Interop
import androidx.camera.core.ImageCapture
import androidx.camera.core.ImageCaptureException
import androidx.camera.core.ImageProxy
import androidx.camera.core.Preview
import androidx.camera.core.resolutionselector.ResolutionSelector
import androidx.camera.core.resolutionselector.ResolutionStrategy
import androidx.camera.view.LifecycleCameraController
import androidx.camera.view.PreviewView
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.statusBarsPadding
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Camera
import androidx.compose.material.icons.filled.Settings
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.DropdownMenuItem
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.ExposedDropdownMenuAnchorType
import androidx.compose.material3.ExposedDropdownMenuBox
import androidx.compose.material3.ExposedDropdownMenuDefaults
import androidx.compose.material3.ExtendedFloatingActionButton
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.OutlinedTextFieldDefaults
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Slider
import androidx.compose.material3.Surface
import androidx.compose.material3.Switch
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.getValue
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Alignment.Companion.BottomStart
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.ImageBitmap
import androidx.compose.ui.graphics.asImageBitmap
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import androidx.compose.ui.viewinterop.AndroidView
import androidx.compose.ui.window.Popup
import androidx.compose.ui.window.PopupProperties
import androidx.core.content.ContextCompat
import androidx.lifecycle.LifecycleOwner
import androidx.lifecycle.compose.LocalLifecycleOwner
import androidx.lifecycle.compose.collectAsStateWithLifecycle
import androidx.lifecycle.viewmodel.compose.viewModel
import java.util.concurrent.Executor

data class CameraActions(
    val onExposureChange: (Float) -> Unit,
    val onResolutionChange: (CameraResolution) -> Unit,
    val onAutoChange: (Boolean) -> Unit,
    val onIsoChange: (Float) -> Unit,
    val onShutterChange: (Long) -> Unit,
    val onPhotoCaptured: (Bitmap) -> Unit,
    val onIsSettingsVisibleChange: (Boolean) -> Unit,
)

@Composable
fun CameraScreen(viewModel: CameraViewModel = viewModel()) {
    val cameraState: CameraState by viewModel.state.collectAsStateWithLifecycle()

    CameraContent(
        state = cameraState,
        actions = CameraActions(
            onExposureChange = viewModel::updateExposure,
            onResolutionChange = viewModel::updateResolution,
            onAutoChange = viewModel::updateAuto,
            onIsoChange = viewModel::updateIso,
            onShutterChange = viewModel::updateShutterSpeed,
            onIsSettingsVisibleChange = viewModel::updateIsSettingsVisible,
            onPhotoCaptured = viewModel::storePhotoInGallery,
        )
    )
}

@androidx.annotation.OptIn(ExperimentalCamera2Interop::class)
@OptIn(ExperimentalMaterial3Api::class)
@Composable
private fun CameraContent(
    state: CameraState,
    actions: CameraActions,
) {

    val context: Context = LocalContext.current
    val lifecycleOwner: LifecycleOwner = LocalLifecycleOwner.current
    val cameraController: LifecycleCameraController = remember { LifecycleCameraController(context) }
    var previewView by remember { mutableStateOf<PreviewView?>(null) }

    LaunchedEffect(state.resolution, state.iso, state.shutterSpeedNanos, state.auto) {
        kotlinx.coroutines.delay(300)

        val selector = getResolutionSelector(state.resolution.size)
        cameraController.previewResolutionSelector = selector
        cameraController.imageCaptureResolutionSelector = selector
        cameraController.setEnabledUseCases(LifecycleCameraController.IMAGE_CAPTURE or LifecycleCameraController.VIDEO_CAPTURE)
        cameraController.isPinchToZoomEnabled = true

        if (previewView == null) {
            return@LaunchedEffect
        }


        val cameraControl = cameraController.cameraControl ?: return@LaunchedEffect
        val control = Camera2CameraControl.from(cameraControl)
        val builder = Preview.Builder()

        val captureRequestOptions = if (state.auto) {
            CaptureRequestOptions.Builder()
                .setCaptureRequestOption(CaptureRequest.CONTROL_AE_MODE, CaptureRequest.CONTROL_AE_MODE_ON)
                .build()
        } else {
            CaptureRequestOptions.Builder()
                .setCaptureRequestOption(CaptureRequest.CONTROL_AE_MODE, CaptureRequest.CONTROL_AE_MODE_OFF)
                .setCaptureRequestOption(CaptureRequest.SENSOR_SENSITIVITY, state.iso.toInt())
                .setCaptureRequestOption(CaptureRequest.SENSOR_EXPOSURE_TIME, state.shutterSpeedNanos)
                .build()
        }
        control.setCaptureRequestOptions(captureRequestOptions)

        val preview = builder.build()
        preview.surfaceProvider = previewView!!.surfaceProvider
    }

    Scaffold(
        modifier = Modifier.fillMaxSize(),
        floatingActionButton = {
            ExtendedFloatingActionButton(
                text = { Text(text = "Take photo") },
                onClick = { capturePhoto(context, cameraController, actions.onPhotoCaptured) },
                icon = { Icon(imageVector = Icons.Default.Camera, contentDescription = "Camera capture icon") }
            )
        },
    ) { paddingValues: PaddingValues ->

        Box(modifier = Modifier.fillMaxSize()) {
            AndroidView(
                modifier = Modifier
                    .fillMaxSize()
                    .padding(paddingValues),
                factory = { context ->
                    PreviewView(context).apply {
                        layoutParams = LinearLayout.LayoutParams(MATCH_PARENT, MATCH_PARENT)
                        implementationMode = PreviewView.ImplementationMode.COMPATIBLE
                        scaleType = PreviewView.ScaleType.FILL_CENTER
                        previewView = this
                    }
                },
                update = { previewView ->
                    previewView.controller = cameraController
                    cameraController.bindToLifecycle(lifecycleOwner)
                }
            )

            IconButton(
                onClick = { actions.onIsSettingsVisibleChange(!state.isSettingsVisible) },
                modifier = Modifier
                    .align(Alignment.TopEnd)
                    .statusBarsPadding()
                    .padding(16.dp)
                    .background(Color.Black.copy(alpha = 0.4f), CircleShape) // Background for visibility
            ) {
                Icon(
                    imageVector = Icons.Default.Settings,
                    contentDescription = "Open Settings",
                    tint = Color.White
                )
            }

            if (state.isSettingsVisible) {
                Popup(
                    alignment = Alignment.TopCenter,
                    onDismissRequest = { actions.onIsSettingsVisibleChange(false) },
                    properties = PopupProperties(focusable = true)
                ) {
                    CameraSettingsPanel(
                        state = state,
                        actions = actions,
                        cameraController = cameraController,
                    )
                }
            }

            if (state.capturedImage != null) {
                LastPhotoPreview(
                    modifier = Modifier.align(alignment = BottomStart),
                    lastCapturedPhoto = state.capturedImage,
                )
            }
        }
    }
}

fun getResolutionSelector(targetSize: Size): ResolutionSelector {
    val strategy = ResolutionStrategy(
        targetSize,
        ResolutionStrategy.FALLBACK_RULE_CLOSEST_HIGHER_THEN_LOWER
    )
    return ResolutionSelector.Builder()
        .setResolutionStrategy(strategy)
        .build()
}

private fun capturePhoto(
    context: Context,
    cameraController: LifecycleCameraController,
    onPhotoCaptured: (Bitmap) -> Unit
) {
    val mainExecutor: Executor = ContextCompat.getMainExecutor(context)

    cameraController.takePicture(mainExecutor, object : ImageCapture.OnImageCapturedCallback() {
        override fun onCaptureSuccess(image: ImageProxy) {
            val correctedBitmap: Bitmap = image
                .toBitmap()
                .rotateBitmap(image.imageInfo.rotationDegrees)

            Log.i("capturePhoto", "Capture photo ${correctedBitmap.width}x${correctedBitmap.height}")
            onPhotoCaptured(correctedBitmap)
            image.close()
        }

        override fun onError(exception: ImageCaptureException) {
            Log.e("CameraContent", "Error capturing image", exception)
        }
    })
}

fun Bitmap.rotateBitmap(rotationDegrees: Int): Bitmap {
    val matrix = Matrix().apply {
        postRotate(-rotationDegrees.toFloat())
        // Flip the image vertically to correct the mirror effect
        // when using the front camera.
        // Remove this line if you don't want the flip.
        postScale(-1f, 1f)
    }

    return Bitmap.createBitmap(this, 0, 0, width, height, matrix, true)
}

@Composable
fun CameraSettingsPanel(
    state: CameraState,
    actions: CameraActions,
    cameraController: LifecycleCameraController,
) {
    val zoomState by cameraController.zoomState.observeAsState()
    val currentZoomRatio = zoomState?.zoomRatio ?: 1.0f
    val minZoom = zoomState?.minZoomRatio ?: 1f
    val maxZoom = zoomState?.maxZoomRatio ?: 1f
    val zoomRange = minZoom..maxZoom

    Surface(
        modifier = Modifier
            .fillMaxWidth()
            .fillMaxHeight(0.95f),
        color = Color.Black.copy(alpha = 0.8f),
        shape = RoundedCornerShape(bottomStart = 16.dp, bottomEnd = 16.dp)
    ) {
        Column(
            modifier = Modifier.padding(24.dp),
            verticalArrangement = Arrangement.spacedBy(16.dp)
        ) {
            Text("Camera Settings", style = MaterialTheme.typography.titleLarge)

            // Exposure Slider
            Text("Exposure: ${state.exposure.toInt()}")
            Slider(
                value = state.exposure,
                onValueChange = {
                    actions.onExposureChange(it)
                    cameraController.cameraControl?.setExposureCompensationIndex(it.toInt())
                },
                valueRange = -16f..16f, // Typical range, check camera capabilities for exacts
                steps = 9
            )

            // Resolution
            Text("Resolution")
            Row {
                ResolutionDropdown(
                    currentResolution = state.resolution,
                    onResolutionChange = actions.onResolutionChange,
                )
            }

            // Auto checkbox
            Text("Auto")
            Row {
                Switch(
                    checked = state.auto,
                    onCheckedChange = actions.onAutoChange
                )
            }

            if (!state.auto) {
                // ISO Slider (Range typically 100 - 3200)
                Text("ISO: ${state.iso.toInt()}")
                Slider(
                    value = state.iso,
                    onValueChange = actions.onIsoChange,
                    valueRange = 100f..3200f,
                    steps = 10
                )

                // Shutter Speed Slider
                // Represented in Nanoseconds: 1/1000s = 1,000,000ns
                Text("Shutter: 1/${(1_000_000_000L / state.shutterSpeedNanos)}s", color = Color.White)
                Slider(
                    value = state.shutterSpeedNanos.toFloat(),
                    onValueChange = { actions.onShutterChange(it.toLong()) },
                    valueRange = 1_000_000f..100_000_000f, // 1/1000s to 1/10s
                )
            }

            Text(
                text = "Zoom: ${"%.1f".format(currentZoomRatio)}x",
                color = Color.White
            )
            Slider(
                value = currentZoomRatio,
                onValueChange = {
                    cameraController.setZoomRatio(it)
                },
                valueRange = zoomRange,
            )
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun ResolutionDropdown(
    currentResolution: CameraResolution,
    onResolutionChange: (CameraResolution) -> Unit
) {
    var expanded by remember { mutableStateOf(false) }

    ExposedDropdownMenuBox(
        expanded = expanded,
        onExpandedChange = { expanded = !expanded }
    ) {
        OutlinedTextField(
            value = currentResolution.label,
            onValueChange = {},
            readOnly = true, // Prevents keyboard from popping up
            singleLine = true,
            trailingIcon = { ExposedDropdownMenuDefaults.TrailingIcon(expanded = expanded) },
            colors = OutlinedTextFieldDefaults.colors(
                disabledLabelColor = Color.White,
                focusedTextColor = Color.White,
                unfocusedTextColor = Color.White,
                disabledTextColor = Color.White,
            ),
            modifier = Modifier
                .menuAnchor(ExposedDropdownMenuAnchorType.PrimaryNotEditable)
                .fillMaxWidth()
        )

        ExposedDropdownMenu(
            expanded = expanded,
            onDismissRequest = { expanded = false },
            modifier = Modifier.background(Color.DarkGray)
        ) {
            CameraResolution.entries.forEach { res ->
                DropdownMenuItem(
                    text = {
                        Text(
                            text = "${res.label} (${res.size.width}x${res.size.height})",
                            color = Color.White
                        )
                    },
                    onClick = {
                        onResolutionChange(res)
                        expanded = false // Close menu after selection
                    },
                    contentPadding = ExposedDropdownMenuDefaults.ItemContentPadding
                )
            }
        }
    }
}

@Composable
private fun LastPhotoPreview(
    modifier: Modifier = Modifier,
    lastCapturedPhoto: Bitmap
) {

    val capturedPhoto: ImageBitmap = remember(lastCapturedPhoto.hashCode()) { lastCapturedPhoto.asImageBitmap() }

    Card(
        modifier = modifier
            .size(128.dp)
            .padding(16.dp),
        elevation = CardDefaults.cardElevation(defaultElevation = 8.dp),
        shape = MaterialTheme.shapes.large
    ) {
        Image(
            bitmap = capturedPhoto,
            contentDescription = "Last captured photo",
            contentScale = ContentScale.Crop
        )
    }
}

@androidx.compose.ui.tooling.preview.Preview
@Composable
fun PreviewCameraContent() {
    val state = CameraState()
    val actions = CameraActions(
        onExposureChange = {},
        onResolutionChange = {},
        onAutoChange = {},
        onIsoChange = {},
        onShutterChange = {},
        onPhotoCaptured = {},
        onIsSettingsVisibleChange = {}
    )
    CameraContent(
        state,
        actions,
    )
}
package app.kiddos.objectdetection.features.camera

import android.content.Context
import android.graphics.Bitmap
import android.graphics.Color
import android.graphics.Matrix
import android.util.Log
import android.view.ViewGroup.LayoutParams.MATCH_PARENT
import android.widget.LinearLayout
import androidx.camera.core.CameraSelector
import androidx.camera.core.ImageAnalysis
import androidx.camera.core.ImageCapture
import androidx.camera.core.ImageCaptureException
import androidx.camera.core.ImageProxy
import androidx.camera.view.LifecycleCameraController
import androidx.camera.view.PreviewView
import androidx.compose.foundation.Canvas
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Camera
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.ExtendedFloatingActionButton
import androidx.compose.material3.Icon
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment.Companion.BottomStart
import androidx.compose.ui.Modifier
import androidx.compose.ui.geometry.Offset
import androidx.compose.ui.geometry.Size
import androidx.compose.ui.graphics.ImageBitmap
import androidx.compose.ui.graphics.asImageBitmap
import androidx.compose.ui.graphics.drawscope.Stroke
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.layout.onSizeChanged
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.TextStyle
import androidx.compose.ui.text.drawText
import androidx.compose.ui.text.rememberTextMeasurer
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.compose.ui.viewinterop.AndroidView
import androidx.core.content.ContextCompat
import androidx.lifecycle.LifecycleOwner
import androidx.lifecycle.compose.LocalLifecycleOwner
import androidx.lifecycle.compose.collectAsStateWithLifecycle
import androidx.lifecycle.viewmodel.compose.viewModel
import com.google.mlkit.vision.objects.DetectedObject
import java.util.concurrent.Executor
import java.util.concurrent.Executors

@Composable
fun CameraScreen(viewModel: CameraViewModel = viewModel()) {
    val cameraState: CameraState by viewModel.state.collectAsStateWithLifecycle()

    CameraContent(
        onPhotoCaptured = viewModel::storePhotoInGallery,
        lastCapturedPhoto = cameraState.capturedImage
    )
}

@Composable
private fun CameraContent(
    onPhotoCaptured: (Bitmap) -> Unit,
    lastCapturedPhoto: Bitmap? = null
) {

    val context: Context = LocalContext.current
    val lifecycleOwner: LifecycleOwner = LocalLifecycleOwner.current

    var detectedObjectsInfo by remember { mutableStateOf<List<DetectedObject>>(emptyList()) }
    var imageWidth by remember { mutableStateOf(480) }
    var imageHeight by remember { mutableStateOf(640) }
    val objectAnalyzer = remember {
        ObjectDetectorAnalyzer { objects, w, h ->
            detectedObjectsInfo = objects
            imageWidth = w
            imageHeight = h
        }
    }
    Log.d("image size: ", "${imageWidth}x${imageHeight}")
    val cameraController: LifecycleCameraController = remember {
        LifecycleCameraController(context).apply {
            this.cameraSelector = CameraSelector.DEFAULT_BACK_CAMERA
            this.setImageAnalysisAnalyzer(
                Executors.newSingleThreadExecutor(), // or a background executor
                objectAnalyzer
            )
            this.imageAnalysisBackpressureStrategy = ImageAnalysis.STRATEGY_KEEP_ONLY_LATEST
        }
    }

    Scaffold(
        modifier = Modifier.fillMaxSize(),
        floatingActionButton = {
            ExtendedFloatingActionButton(
                text = { Text(text = "Take photo") },
                onClick = { capturePhoto(context, cameraController, onPhotoCaptured) },
                icon = { Icon(imageVector = Icons.Default.Camera, contentDescription = "Camera capture icon") }
            )
        }
    ) { paddingValues: PaddingValues ->

        Box(
            modifier = Modifier
                .fillMaxSize()
                .padding(paddingValues)
        ) {
            AndroidView(
                modifier = Modifier
                    .fillMaxSize()
                    .padding(paddingValues),
                factory = { context ->
                    PreviewView(context).apply {
                        layoutParams = LinearLayout.LayoutParams(MATCH_PARENT, MATCH_PARENT)
                        setBackgroundColor(Color.BLACK)
                        implementationMode = PreviewView.ImplementationMode.COMPATIBLE
                        scaleType = PreviewView.ScaleType.FILL_CENTER
                    }.also { previewView ->
                        previewView.controller = cameraController
                        cameraController.bindToLifecycle(lifecycleOwner)
                    }
                }
            )

            ObjectDetectionResult(
                detectedObjectsInfo,
                imageWidth, // Width of the image processed by ML Kit
                imageHeight // Height of the image processed by ML Kit
            )

            if (lastCapturedPhoto != null) {
                LastPhotoPreview(
                    modifier = Modifier.align(alignment = BottomStart),
                    lastCapturedPhoto = lastCapturedPhoto
                )
            }
        }
    }
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

@Preview
@Composable
fun PreviewCameraContent() {
    CameraContent(
        onPhotoCaptured = {}
    )
}

@Composable
fun ObjectDetectionResult(
    detectedObjects: List<DetectedObject>,
    imageWidth: Int,
    imageHeight: Int
) {
    var canvasSize by remember { mutableStateOf(Size.Zero) }
    val textMeasurer = rememberTextMeasurer()

    Box(modifier = Modifier.fillMaxSize()) {
        Canvas(
            modifier = Modifier
                .fillMaxSize()
                .onSizeChanged { size ->
                    canvasSize = Size(size.width.toFloat(), size.height.toFloat())
                }
        ) {
            if (canvasSize == Size.Zero || imageWidth == 0 || imageHeight == 0) return@Canvas

            // Calculate scale factors with FIT_CENTER
            val scaleX = canvasSize.width / imageWidth.toFloat()
            val scaleY = canvasSize.height / imageHeight.toFloat()

            detectedObjects.filter {
                it.labels.isNotEmpty()
            }.forEach { detectedObject ->
                val boundingBox = detectedObject.boundingBox

                val left = boundingBox.left * scaleX
                val top = boundingBox.top * scaleY
                val right = boundingBox.right * scaleX
                val bottom = boundingBox.bottom * scaleY

                // Draw bounding box
                drawRect(
                    color = androidx.compose.ui.graphics.Color.Red,
                    topLeft = Offset(left, top),
                    size = Size(right - left, bottom - top),
                    style = Stroke(width = 2.dp.toPx())
                )

                // Draw labels
                detectedObject.labels.firstOrNull()?.let { label ->
                    val text = "${label.text} (${String.format("%.2f", label.confidence)})"

                    drawText(
                        text = text,
                        textMeasurer = textMeasurer,
                        style = TextStyle(color = androidx.compose.ui.graphics.Color.Red, fontSize = 20.sp),
                        topLeft = Offset(left, top)
                    )
                }
            }
        }
    }
}

package app.kiddos.ocrexample.features.camera

import android.graphics.Bitmap

data class CameraState(
    val capturedImage: Bitmap? = null,
)
package app.kiddos.imageclassification.features.camera

import android.graphics.Bitmap

data class CameraState(
    val capturedImage: Bitmap? = null,
)
package app.kiddos.cameraxbasic.features.camera

import android.graphics.Bitmap

data class CameraState(
  val capturedImage: Bitmap? = null,
)
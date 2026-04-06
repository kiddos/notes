package app.kiddos.ocrexample.features.camera

data class DetectedText(
    val text: String,
    val boundingBox: android.graphics.Rect
)
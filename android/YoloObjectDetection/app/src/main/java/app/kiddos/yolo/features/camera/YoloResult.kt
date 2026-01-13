package app.kiddos.yolo.features.camera

import android.graphics.RectF

data class YoloResult(val label: String, val confidence: Float, val boundingBox: RectF)
package app.kiddos.ocrexample.features.camera

import android.util.Log
import com.google.mlkit.vision.common.InputImage
import com.google.mlkit.vision.text.Text
import com.google.mlkit.vision.text.TextRecognition
import com.google.mlkit.vision.text.chinese.ChineseTextRecognizerOptions

class OcrManager {

    companion object {
        const val TAG = "OcrManager"
    }

    private val recognizer = TextRecognition.getClient(
        ChineseTextRecognizerOptions.Builder().build()
    )

    fun runTextRecognition(image: InputImage, onResult: (List<DetectedText>) -> Unit) {
        recognizer.process(image)
            .addOnSuccessListener { visionText ->
                val detectedList = visionText.textBlocks.map { block ->
                    DetectedText(block.text, block.boundingBox ?: android.graphics.Rect())
                }
                onResult(detectedList)
            }
            .addOnFailureListener { e ->
                Log.e(TAG, "Text recognition failed", e)
            }
    }

    fun close() {
        recognizer.close()
    }
}
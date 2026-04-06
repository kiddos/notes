```kotlin
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

    fun runTextRecognition(image: InputImage) {
        recognizer.process(image)
            .addOnSuccessListener { visionText ->
                processTextRecognitionResult(visionText)
            }
            .addOnFailureListener { e ->
                Log.e(TAG, "Text recognition failed", e)
            }
    }

    private fun processTextRecognitionResult(result: Text) {
        val resultText = result.text
        for (block in result.textBlocks) {
            val blockText = block.text
            val blockCornerPoints = block.cornerPoints
            val blockFrame = block.boundingBox
            for (line in block.lines) {
                val lineText = line.text
                for (element in line.elements) {
                    val elementText = element.text
                    println("Recognized Text: $elementText")
                    // Here you can access specific words and their positions
                }
            }
        }
    }

    fun close() {
        recognizer.close()
    }
}
```

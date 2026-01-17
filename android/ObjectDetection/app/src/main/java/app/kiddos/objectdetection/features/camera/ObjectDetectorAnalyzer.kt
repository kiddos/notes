package app.kiddos.objectdetection.features.camera

import android.util.Log
import androidx.camera.core.ImageAnalysis
import androidx.camera.core.ImageProxy
import com.google.mlkit.common.model.LocalModel
import com.google.mlkit.vision.common.InputImage
import com.google.mlkit.vision.objects.DetectedObject
import com.google.mlkit.vision.objects.ObjectDetection
import com.google.mlkit.vision.objects.custom.CustomObjectDetectorOptions

class ObjectDetectorAnalyzer(
    private val onObjectsDetected: (List<DetectedObject>, width: Int, height: Int) -> Unit
) : ImageAnalysis.Analyzer {

    val localModel = LocalModel.Builder()
        .setAssetFilePath("object_labeler.tflite")
        .build()

    val customObjectDetectorOptions =
        CustomObjectDetectorOptions.Builder(localModel)
            .setDetectorMode(CustomObjectDetectorOptions.STREAM_MODE)
            .enableClassification()
            .enableMultipleObjects()
            .setClassificationConfidenceThreshold(0.7f)
            .setMaxPerObjectLabelCount(10)
            .build()

    val detector =
        ObjectDetection.getClient(customObjectDetectorOptions)

    @androidx.annotation.OptIn(androidx.camera.core.ExperimentalGetImage::class)
    override fun analyze(imageProxy: ImageProxy) {
        val mediaImage = imageProxy.image
        if (mediaImage != null) {
            val image = InputImage.fromMediaImage(mediaImage, imageProxy.imageInfo.rotationDegrees)

            detector.process(image)
                .addOnSuccessListener { detectedObjects ->
                    val rotationDegrees = imageProxy.imageInfo.rotationDegrees

                    val mlKitImageWidth = if (rotationDegrees == 90 || rotationDegrees == 270) {
                        imageProxy.height
                    } else {
                        imageProxy.width
                    }
                    val mlKitImageHeight = if (rotationDegrees == 90 || rotationDegrees == 270) {
                        imageProxy.width
                    } else {
                        imageProxy.height
                    }

                    onObjectsDetected(detectedObjects, mlKitImageWidth, mlKitImageHeight)
                }
                .addOnFailureListener { e ->
                    Log.e("ObjectDetectorAnalyzer", "Object detection failed", e)
                }
                .addOnCompleteListener {
                    imageProxy.close() // Crucial: always close the ImageProxy
                }
        } else {
            imageProxy.close() // Close if mediaImage is null
        }
    }
}

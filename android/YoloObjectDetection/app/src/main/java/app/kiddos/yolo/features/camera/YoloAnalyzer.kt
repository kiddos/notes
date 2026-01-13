package app.kiddos.yolo.features.camera

import android.content.Context
import android.graphics.RectF
import android.util.Log
import androidx.annotation.OptIn
import androidx.camera.core.ExperimentalGetImage
import androidx.camera.core.ImageAnalysis
import androidx.camera.core.ImageProxy
import app.kiddos.yolo.R
import app.kiddos.yolo.ml.Yolo11nFloat32
import org.tensorflow.lite.DataType
import org.tensorflow.lite.gpu.CompatibilityList
import org.tensorflow.lite.support.common.ops.NormalizeOp
import org.tensorflow.lite.support.image.ImageProcessor
import org.tensorflow.lite.support.image.TensorImage
import org.tensorflow.lite.support.image.ops.ResizeOp
import org.tensorflow.lite.support.image.ops.Rot90Op
import org.tensorflow.lite.support.model.Model

class YoloAnalyzer(
    private val context: Context,
    private val onResult: (List<YoloResult>, width: Int, height: Int) -> Unit
) : ImageAnalysis.Analyzer {

    private val model: Yolo11nFloat32 by lazy {
        val compatList = CompatibilityList()

        val optionsBuilder = Model.Options.Builder()
        try {
            if (compatList.isDelegateSupportedOnThisDevice) {
                optionsBuilder.setDevice(Model.Device.NNAPI)
                Log.d(TAG, "This device is GPU Compatible ")
            } else {
                optionsBuilder.setDevice(Model.Device.CPU).setNumThreads(4)
                Log.d(TAG, "This device is GPU Incompatible ")
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error: ${e.message}", e)
        }
        Yolo11nFloat32.newInstance(context)
    }

    private val labels: List<String> by lazy {
        val inputStream = context.resources.openRawResource(R.raw.coco80)
        inputStream.bufferedReader().use { it.readText().split("\n") }
    }

    @OptIn(ExperimentalGetImage::class)
    override fun analyze(imageProxy: ImageProxy) {
        val mediaImage = imageProxy.image

        if (mediaImage != null) {
            val startTime = System.currentTimeMillis()
            val image = imageProxy.toBitmap()

            val width = 640
            val height = 640
            val imageProcessor = ImageProcessor.Builder()
                // Add rotation based on the image metadata
                .add(Rot90Op(imageProxy.imageInfo.rotationDegrees / 90))
                // Resize the image to the target dimensions
                .add(ResizeOp(height, width, ResizeOp.ResizeMethod.BILINEAR))
                // Normalize the image to a [0, 1] range if the model requires FLOAT32 input.
                // Adjust the values if your model has a different normalization scheme.
                .add(NormalizeOp(0f, 255f))
                .build()
            val tensorImage = TensorImage(DataType.FLOAT32)
            tensorImage.load(image)
            val transformed = imageProcessor.process(tensorImage)

            val outputs = model.process(transformed.tensorBuffer).outputFeature0AsTensorBuffer
            val endTime = System.currentTimeMillis()
            Log.d(TAG, "Inference time: ${endTime - startTime}ms, shape: ${outputs.floatArray.size}")

            val data = outputs.floatArray
            val output = ArrayList<YoloResult>()

            val sampleCount = 300
            val threshold = 0.8
            for (i in 0 until sampleCount) {
                val offset = i * 6

                val x1 = data[offset + 0]
                val y1 = data[offset + 1]
                val x2 = data[offset + 2]
                val y2 = data[offset + 3]
                val score = data[offset + 4]
                val classIdx = data[offset + 5].toInt()

                if (score > threshold) {
                    val rect = RectF(x1, y1, x2, y2)

                    output.add(YoloResult(
                        label = labels.getOrElse(classIdx) { "Unknown" },
                        confidence = score,
                        boundingBox = rect
                    ))
                }
            }

            val rotationDegrees = imageProxy.imageInfo.rotationDegrees
            val imageWidth = if (rotationDegrees == 90 || rotationDegrees == 270) {
                imageProxy.height
            } else {
                imageProxy.width
            }
            val imageHeight = if (rotationDegrees == 90 || rotationDegrees == 270) {
                imageProxy.width
            } else {
                imageProxy.height
            }
            onResult.invoke(applyNMS(output), imageWidth, imageHeight)
        }
        imageProxy.close()
    }

    fun calculateIoU(rect1: RectF, rect2: RectF): Float {
        val intersection = RectF()
        if (!intersection.setIntersect(rect1, rect2)) return 0f
        val intersectionArea = intersection.width() * intersection.height()
        val unionArea = (rect1.width() * rect1.height()) + (rect2.width() * rect2.height()) - intersectionArea
        return intersectionArea / unionArea
    }

    fun applyNMS(detections: List<YoloResult>, threshold: Float = 0.45f): List<YoloResult> {
        val groupedDetections = detections.groupBy { it.label }
        val result = mutableListOf<YoloResult>()

        for (classGroup in groupedDetections.values) {
            val sortedDetections = classGroup.sortedByDescending { it.confidence }.toMutableList()

            while (sortedDetections.isNotEmpty()) {
                val best = sortedDetections.removeAt(0)
                result.add(best)

                val iterator = sortedDetections.iterator()
                while (iterator.hasNext()) {
                    val next = iterator.next()
                    if (calculateIoU(best.boundingBox, next.boundingBox) > threshold) {
                        iterator.remove()
                    }
                }
            }
        }
        return result
    }

    companion object {
        const val TAG = "YoloAnalyzer"
    }
}
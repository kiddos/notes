package app.kiddos.imageclassification.features.camera

import android.content.Context
import android.util.Log
import androidx.annotation.OptIn
import androidx.camera.core.ExperimentalGetImage
import androidx.camera.core.ImageAnalysis
import androidx.camera.core.ImageProxy
import app.kiddos.imageclassification.ml.EfficientnetB5
import com.google.android.gms.common.util.IOUtils
import com.google.gson.Gson
import com.google.gson.reflect.TypeToken
import org.tensorflow.lite.DataType
import org.tensorflow.lite.gpu.CompatibilityList
import org.tensorflow.lite.support.image.ImageProcessor
import org.tensorflow.lite.support.image.TensorImage
import org.tensorflow.lite.support.image.ops.ResizeOp
import org.tensorflow.lite.support.image.ops.Rot90Op
import org.tensorflow.lite.support.model.Model

class ImageClassificationAnalyzer(
  private val context: Context,
  private val onClassificationResult: (List<ClassificationResult>) -> Unit
) : ImageAnalysis.Analyzer {
  private val model: EfficientnetB5 by lazy {
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
    EfficientnetB5.newInstance(context, optionsBuilder.build())
  }

  private val labels: Map<String, String> by lazy {
    loadLabels(context)
  }

  @OptIn(ExperimentalGetImage::class)
  override fun analyze(imageProxy: ImageProxy) {
    val mediaImage = imageProxy.image

    if (mediaImage != null) {
      val image = imageProxy.toBitmap()

      val imageProcessor = ImageProcessor.Builder()
        // Add rotation based on the image metadata
        .add(Rot90Op(imageProxy.imageInfo.rotationDegrees / 90))
        // Resize the image to the target dimensions
        .add(ResizeOp(456, 456, ResizeOp.ResizeMethod.BILINEAR))
        // Normalize the image to a [0, 1] range if the model requires FLOAT32 input.
        // Adjust the values if your model has a different normalization scheme.
        //.add(NormalizeOp(0f, 255f))
        .build()
      val tensorImage = TensorImage(DataType.FLOAT32)
      tensorImage.load(image)
      val transformed = imageProcessor.process(tensorImage)

      val outputs = model.process(transformed.tensorBuffer).outputFeature0AsTensorBuffer
      val result = outputs.floatArray
      val output = ArrayList<ClassificationResult>()
      for (i in result.indices) {
        output.add(ClassificationResult(labels[i.toString()] ?: "Unknown", result[i]))
      }
      output.sortWith<ClassificationResult>(Comparator({ o1, o2 ->
        o2.confidence.compareTo(o1.confidence)
      }))
      onClassificationResult.invoke(output)
    }
    imageProxy.close()
  }

  data class ClassificationResult(val label: String, val confidence: Float)

  companion object {
    const val TAG = "ImageClassificationAnalyzer"
  }

  private fun loadLabels(context: Context): Map<String, String> {
    val inputStream = context.assets.open("imagenet-1k-id2label.json")
    val bytes = IOUtils.toByteArray(inputStream)
    val gson = Gson()
    val jsonText = String(bytes, Charsets.UTF_8)
    val type = object : TypeToken<Map<String, String>>() {}.type
    return gson.fromJson(jsonText, type)
  }
}
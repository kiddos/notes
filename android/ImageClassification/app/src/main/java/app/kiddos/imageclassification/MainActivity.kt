package app.kiddos.imageclassification

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import app.kiddos.imageclassification.features.camera.CameraScreen
import app.kiddos.imageclassification.features.camera.NoPermissionScreen
import app.kiddos.imageclassification.ui.theme.ImageClassificationTheme
import com.google.accompanist.permissions.ExperimentalPermissionsApi
import com.google.accompanist.permissions.isGranted
import com.google.accompanist.permissions.rememberPermissionState

class MainActivity : ComponentActivity() {
  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    enableEdgeToEdge()
    setContent {
      ImageClassificationTheme {
        Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
          MainApp(
            modifier = Modifier.padding(innerPadding)
          )
        }
      }
    }
  }
}

@OptIn(ExperimentalPermissionsApi::class)
@Composable
fun MainApp(modifier: Modifier = Modifier) {
  val cameraPermissionState = rememberPermissionState(android.Manifest.permission.CAMERA)
  Row(modifier = modifier) {
    if (cameraPermissionState.status.isGranted) {
      CameraScreen()
    } else {
      NoPermissionScreen(onRequestPermission = cameraPermissionState::launchPermissionRequest)
    }
  }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
  ImageClassificationTheme {
    MainApp()
  }
}
package app.kiddos.ocrexample

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import app.kiddos.ocrexample.features.camera.CameraScreen
import app.kiddos.ocrexample.features.camera.NoPermissionScreen
import app.kiddos.ocrexample.ui.theme.OCRExampleTheme
import com.google.accompanist.permissions.ExperimentalPermissionsApi
import com.google.accompanist.permissions.isGranted
import com.google.accompanist.permissions.rememberPermissionState

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            OCRExampleTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    MainScreen(
                        modifier = Modifier.padding(innerPadding)
                    )
                }
            }
        }
    }
}

@OptIn(ExperimentalPermissionsApi::class)
@Composable
fun MainScreen(modifier: Modifier = Modifier) {
    val cameraPermissionState = rememberPermissionState(android.Manifest.permission.CAMERA);

    if (cameraPermissionState.status.isGranted) {
        CameraScreen()
    } else {
        NoPermissionScreen(onRequestPermission = cameraPermissionState::launchPermissionRequest)
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    OCRExampleTheme {
        MainScreen()
    }
}
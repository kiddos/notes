package app.kiddos.cameraxbasic.features.camera

import android.graphics.Bitmap
import android.util.Size

enum class CameraResolution(val label: String, val size: Size) {
    STANDARD("480p", Size(640, 480)),
    HD_720P("720p", Size(1280, 720)),
    FHD_1080P("1080p", Size(1920, 1080)),
    UTRAL_HD_4K("4K", Size(3840, 2160)),
}

data class CameraState(
    val capturedImage: Bitmap? = null,
    val exposure: Float = 0f,
    val resolution: CameraResolution = CameraResolution.FHD_1080P,
    val auto: Boolean = true,
    val iso: Float = 100f,
    val shutterSpeedNanos: Long = 16666666L,
    val isSettingsVisible: Boolean = false
)
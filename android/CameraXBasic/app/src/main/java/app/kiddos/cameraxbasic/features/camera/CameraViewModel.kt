package app.kiddos.cameraxbasic.features.camera

import android.graphics.Bitmap
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.flow.update
import kotlinx.coroutines.launch

class CameraViewModel() : ViewModel() {
    private val _state = MutableStateFlow(CameraState())
    val state = _state.asStateFlow()

    fun storePhotoInGallery(bitmap: Bitmap) {
        viewModelScope.launch {
            // savePhotoToGalleryUseCase.call(bitmap)
            updateCapturedPhotoState(bitmap)
        }
    }

    private fun updateCapturedPhotoState(updatedPhoto: Bitmap?) {
        _state.update { it.copy(capturedImage = updatedPhoto) }
    }

    fun updateExposure(value: Float) {
        _state.update { it.copy(exposure = value) }
    }

    fun updateAuto(value: Boolean) {
        _state.update { it.copy(auto = value) }
    }

    fun updateIso(value: Float) {
        _state.update { it.copy(iso = value) }
    }

    fun updateResolution(res: CameraResolution) {
        _state.update { it.copy(resolution = res) }
    }

    fun updateShutterSpeed(value: Long) {
        _state.update { it.copy(shutterSpeedNanos = value) }
    }

    fun updateIsSettingsVisible(value: Boolean) {
        _state.update { it.copy(isSettingsVisible = value) }
    }

    override fun onCleared() {
        _state.value.capturedImage?.recycle()
        super.onCleared()
    }

}
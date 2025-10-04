package app.kiddos.gles3sample

import android.content.res.AssetManager

class GLES3Lib {
    companion object {
        init {
            System.loadLibrary("gles3jni")
        }

        @JvmStatic
        external fun init(assetManager: AssetManager)

        @JvmStatic
        external fun resize(width: Int, height: Int)

        @JvmStatic
        external fun onTouch(dx: Float, dy: Float)

        @JvmStatic
        external fun step()
    }
}
package app.kiddos.gles3sample

import android.content.Context
import android.opengl.GLSurfaceView
import android.view.MotionEvent
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class GLES3JNIView : GLSurfaceView {
    private var previousX = 0f
    private var previousY = 0f

    constructor(context: Context) : super(context) {
        setEGLConfigChooser(8, 8, 8, 0, 16, 0)
        setEGLContextClientVersion(3)
        setRenderer(Renderer(context))
    }

    override fun onTouchEvent(event: MotionEvent): Boolean {
        val x = event.x
        val y = event.y

        when (event.action) {
            MotionEvent.ACTION_MOVE -> {
                val dx = x - previousX
                val dy = y - previousY
                GLES3Lib.onTouch(dx, dy)
            }
        }

        previousX = x
        previousY = y
        return true
    }

    class Renderer : GLSurfaceView.Renderer {
        var context: Context

        constructor(context: Context) {
            this.context = context
        }

        override fun onDrawFrame(gl: GL10?) {
            GLES3Lib.step()
        }

        override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
            GLES3Lib.resize(width, height)
        }

        override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
            GLES3Lib.init(context.assets)
        }
    }
}
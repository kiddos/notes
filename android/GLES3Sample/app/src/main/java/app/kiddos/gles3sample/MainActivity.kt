package app.kiddos.gles3sample

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

class MainActivity : AppCompatActivity() {
    private lateinit var view: GLES3JNIView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        view = GLES3JNIView(this)
        setContentView(view)
    }

    override fun onPause() {
        super.onPause()
        view.onPause()
    }

    override fun onResume() {
        super.onResume()
        view.onResume()
    }
}
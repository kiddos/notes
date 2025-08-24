plugins {
  alias(libs.plugins.android.application)
  alias(libs.plugins.kotlin.android)
  alias(libs.plugins.kotlin.compose)
}

android {
  namespace = "app.kiddos.objectdetection"
  compileSdk = 36

  defaultConfig {
    applicationId = "app.kiddos.objectdetection"
    minSdk = 26
    targetSdk = 36
    versionCode = 1
    versionName = "1.0"

    testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
  }

  buildTypes {
    release {
      isMinifyEnabled = false
      proguardFiles(getDefaultProguardFile("proguard-android-optimize.txt"), "proguard-rules.pro")
    }
  }
  compileOptions {
    sourceCompatibility = JavaVersion.VERSION_11
    targetCompatibility = JavaVersion.VERSION_11
  }
  kotlinOptions {
    jvmTarget = "11"
  }
  buildFeatures {
    compose = true
  }
  aaptOptions {
    noCompress("tflite")
  }
}

dependencies {

  implementation(libs.androidx.core.ktx)
  implementation(libs.androidx.lifecycle.runtime.ktx)
  implementation(libs.androidx.activity.compose)
  implementation(platform(libs.androidx.compose.bom))
  implementation(libs.androidx.ui)
  implementation(libs.androidx.ui.graphics)
  implementation(libs.androidx.ui.tooling.preview)
  implementation(libs.androidx.material3)
  testImplementation(libs.junit)
  androidTestImplementation(libs.androidx.junit)
  androidTestImplementation(libs.androidx.espresso.core)
  androidTestImplementation(platform(libs.androidx.compose.bom))
  androidTestImplementation(libs.androidx.ui.test.junit4)
  debugImplementation(libs.androidx.ui.tooling)
  debugImplementation(libs.androidx.ui.test.manifest)

  implementation(libs.androidx.material.icons.extended.android)
  implementation(libs.androidx.lifecycle.viewmodel.compose)

  implementation(libs.accompanist.permissions)

  // The following line is optional, as the core library is included indirectly by camera-camera2
  implementation(libs.androidx.camera.core)
  implementation(libs.androidx.camera.camera2)
  // If you want to additionally use the CameraX Lifecycle library
  implementation(libs.androidx.camera.lifecycle)
  // If you want to additionally use the CameraX VideoCapture library
  implementation(libs.androidx.camera.video)
  // If you want to additionally use the CameraX View class
  implementation(libs.androidx.camera.view)
  // If you want to additionally add CameraX ML Kit Vision Integration
  implementation(libs.androidx.camera.mlkit.vision)
  // If you want to additionally use the CameraX Extensions library
  implementation(libs.androidx.camera.extensions)

  implementation(libs.object1.detection)
  implementation(libs.object1.detection.custom)
}
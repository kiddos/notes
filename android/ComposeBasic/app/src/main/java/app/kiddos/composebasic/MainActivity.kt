package app.kiddos.composebasic

import android.content.res.Configuration
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.animation.core.animateDpAsState
import androidx.compose.animation.core.tween
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.Button
import androidx.compose.material3.ElevatedButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import app.kiddos.composebasic.ui.theme.ComposeBasicTheme

class MainActivity : ComponentActivity() {
  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    enableEdgeToEdge()
    setContent {
      ComposeBasicTheme {
        Scaffold() { innerPadding ->
          MainApp(Modifier.fillMaxSize().padding(innerPadding))
        }
      }
    }
  }
}

@Composable
fun MainApp(modifier: Modifier = Modifier) {
  var shouldShowOnboarding by rememberSaveable { mutableStateOf(true) }
  Surface(modifier = modifier) {
    if (shouldShowOnboarding) {
      OnboardingScreen(onContinueClicked = { shouldShowOnboarding = false })
    } else {
      MainScreen(Modifier.fillMaxSize())
    }
  }
}

@Composable
fun MainScreen(modifier: Modifier = Modifier) {
  val items = List(1000) { "$it" }
  Surface(modifier = modifier) {
    Column(modifier = Modifier.padding(4.dp)) {
      LazyColumn {
        items(items = items) { item ->
          Item(item)
        }
      }
    }
  }
}

@Composable
fun Item(text: String) {
  var expanded by remember { mutableStateOf(false) }
  val extraPadding = animateDpAsState(
    targetValue = if (expanded) 48.dp else 0.dp,
    animationSpec = tween(
      durationMillis = 600
    )
  )

  Surface(color = MaterialTheme.colorScheme.primary,
    modifier = Modifier.padding(vertical = 4.dp, horizontal = 8.dp)) {
    Row(modifier = Modifier.padding(24.dp)) {
      Column(modifier = Modifier.weight(1f).padding(extraPadding.value)) {
        Text(text = "Hello,")
        Text(text = text)
      }
      ElevatedButton(onClick = { expanded= !expanded}) {
        Text(
          if (expanded) "Show less"  else "Show more"
        )
      }
    }
  }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
  ComposeBasicTheme {
    MainScreen()
  }
}

@Composable
fun OnboardingScreen(modifier: Modifier = Modifier, onContinueClicked: () -> Unit) {
  Column(
    modifier = modifier.fillMaxSize(),
    verticalArrangement = Arrangement.Center,
    horizontalAlignment = Alignment.CenterHorizontally
  ) {
    Text("Welcome to the Basics Codelab!")
    Button(
      modifier = Modifier.padding(vertical = 24.dp),
      onClick = onContinueClicked
    ) {
      Text("Continue")
    }
  }
}

@Preview(showBackground = true, widthDp = 320, heightDp = 320, uiMode = Configuration.UI_MODE_NIGHT_YES)
@Preview(showBackground = true, widthDp = 320, heightDp = 320)
@Composable
fun OnboardingPreview() {
  ComposeBasicTheme {
    OnboardingScreen(onContinueClicked = {})
  }
}
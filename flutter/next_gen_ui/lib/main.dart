import 'dart:io' show Platform;
import 'dart:ui';

import 'package:flutter/foundation.dart' show kIsWeb;
import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:provider/provider.dart';
import 'package:window_size/window_size.dart';

import 'types.dart';
import 'title_screen.dart';

Future<FragmentPrograms> loadFragmentPrograms() async {
  return (
    orb: await FragmentProgram.fromAsset('assets/shaders/orb.frag'),
    ui: await FragmentProgram.fromAsset('assets/shaders/ui.frag')
  );
}

void main() {
  if (!kIsWeb && (Platform.isWindows || Platform.isLinux || Platform.isMacOS)) {
    WidgetsFlutterBinding.ensureInitialized();
    setWindowMinSize(const Size(800, 500));
  }
  Animate.restartOnHotReload = true;

  runApp(FutureProvider<FragmentPrograms?>(
    create: (context) => loadFragmentPrograms(),
    initialData: null,
    child: const MainApp(),
  ));
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      themeMode: ThemeMode.dark,
      theme: ThemeData(brightness: Brightness.dark),
      home: const TitleScreen(),
    );
  }
}

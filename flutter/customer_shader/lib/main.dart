import 'dart:ui';

import 'package:flutter/material.dart';

late FragmentProgram fragmentProgram;

void main() async {
  fragmentProgram =
      await FragmentProgram.fromAsset('assets/shaders/simple.frag');
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: CustomPaint(
        painter: MainPainter(
          color: const Color.fromARGB(100, 175, 91, 214),
          shader: fragmentProgram.fragmentShader(),
        ),
      ),
    );
  }
}

class MainPainter extends CustomPainter {
  const MainPainter({required this.color, required this.shader});
  final Color color;
  final FragmentShader shader;

  @override
  void paint(Canvas canvas, Size size) {
    shader.setFloat(0, color.red.toDouble() / 255.0);
    shader.setFloat(1, color.green.toDouble() / 255.0);
    shader.setFloat(2, color.blue.toDouble() / 255.0);
    shader.setFloat(3, color.alpha.toDouble() / 255.0);

    shader.setFloat(4, size.width);
    shader.setFloat(5, size.height);
    
    canvas.drawRect(
      Rect.fromLTWH(0, 0, size.width, size.height),
      Paint()..shader = shader,
    );
  }

  @override
  bool shouldRepaint(MainPainter oldDelegate) {
    return color != oldDelegate.color;
  }
}

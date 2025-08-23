import 'dart:math';

import 'package:flutter/material.dart';

class UIScaler extends StatelessWidget {
  const UIScaler({
    super.key,
    required this.child,
    required this.alignment,
    this.referenceHeight = 1080,
  });

  final int referenceHeight;
  final Widget child;
  final Alignment alignment;

  @override
  Widget build(BuildContext context) {
    final screenSize = MediaQuery.of(context).size;
    final double scale = min(screenSize.height / referenceHeight, 1.0);
    return Transform.scale(
      scale: scale,
      alignment: alignment,
      child: child,
    );
  }
}

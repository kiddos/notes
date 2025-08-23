import 'dart:math';
import 'dart:ui';

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_animate/flutter_animate.dart';

import 'orb_shader_config.dart';
import 'orb_shader_widget.dart';
import 'styles.dart';
import 'title_screen_ui.dart';
import 'particle_overlay.dart';

class TitleScreen extends StatefulWidget {
  const TitleScreen({super.key});

  @override
  State<TitleScreen> createState() => _TitleScreenState();
}

class _TitleScreenState extends State<TitleScreen>
    with SingleTickerProviderStateMixin {
  final _orbKey = GlobalKey<OrbShaderWidgetState>();

  final _minReceivedLightAmt = 0.35;
  final _maxReceivedLightAmt = 0.7;

  final _minEmitLightAmt = 0.5;
  final _maxEmitLightAmt = 1.0;

  Offset _mouse = Offset.zero;

  Color get _emitColor =>
      AppColors.emitColors[_difficultyOverride ?? _difficulty];
  Color get _orbColor =>
      AppColors.orbColors[_difficultyOverride ?? _difficulty];

  /// Currently selected difficulty
  int _difficulty = 0;

  /// Currently focused difficulty (if any)
  int? _difficultyOverride;
  double _orbEnergy = 0;
  double _minOrbEnergy = 0;

  double get _finalReceiveLightAmt {
    final light =
        lerpDouble(_minReceivedLightAmt, _maxReceivedLightAmt, _orbEnergy) ?? 0;
    return light + _pulseEffect.value * 0.05 * _orbEnergy;
  }

  double get _finalEmitLightAmt {
    return lerpDouble(_minEmitLightAmt, _maxEmitLightAmt, _orbEnergy) ?? 0;
  }

  late final _pulseEffect = AnimationController(
    vsync: this,
    duration: _getRandomPulseDuration(),
    lowerBound: -1,
    upperBound: 1,
  );

  Duration _getRandomPulseDuration() {
    double t = 100 + 200 * Random().nextDouble();
    return Duration(milliseconds: t.toInt());
  }

  double _getMinEnergyForDifficulty(int difficulty) {
    return switch (difficulty) {
      1 => 0.3,
      2 => 0.6,
      _ => 0,
    };
  }

  @override
  void initState() {
    super.initState();
    _pulseEffect.forward();
    _pulseEffect.addListener(_handlePulseEffectUpdate);
  }

  void _handlePulseEffectUpdate() {
    if (_pulseEffect.status == AnimationStatus.completed) {
      _pulseEffect.reverse();
      _pulseEffect.duration = _getRandomPulseDuration();
    } else if (_pulseEffect.status == AnimationStatus.dismissed) {
      _pulseEffect.duration = _getRandomPulseDuration();
      _pulseEffect.forward();
    }
  }

  void _handleDifficultyPressed(int value) {
    setState(() => _difficulty = value);
    _bumpMinEnergy();
  }

  Future<void> _bumpMinEnergy([double amount = 0.1]) async {
    setState(() {
      _minOrbEnergy = _getMinEnergyForDifficulty(_difficulty) + amount;
    });
    await Future<void>.delayed(const Duration(milliseconds: 200));
    setState(() {
      _minOrbEnergy = _getMinEnergyForDifficulty(_difficulty);
    });
  }

  void _handleStartPressed() => _bumpMinEnergy(0.3);

  void _handleDifficultyFocused(int? value) {
    setState(() {
      _difficultyOverride = value;
      if (value == null) {
        _minOrbEnergy = _getMinEnergyForDifficulty(_difficulty);
      } else {
        _minOrbEnergy = _getMinEnergyForDifficulty(value);
      }
    });
  }

  void _handleMouseMove(PointerHoverEvent e) {
    setState(() {
      _mouse = e.localPosition;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      body: Center(
        child: MouseRegion(
          onHover: _handleMouseMove,
          child: _AnimatedColor(
            orbColor: _orbColor,
            emitColor: _emitColor,
            builder: (_, orbColor, emitColor) {
              return Stack(
                children: [
                  Image.asset('assets/images/bg-base.jpg'),
                  _LitImage(
                    color: orbColor,
                    imageSrc: 'assets/images/bg-light-receive.png',
                    pulseEffect: _pulseEffect,
                    lightAmt: _finalEmitLightAmt,
                  ),
                  Positioned.fill(
                    child: Stack(
                      children: [
                        OrbShaderWidget(
                          key: _orbKey,
                          mousePos: _mouse,
                          minEnergy: _minOrbEnergy,
                          config: OrbShaderConfig(
                            ambientLightColor: orbColor,
                            materialColor: orbColor,
                            lightColor: orbColor,
                          ),
                          onUpdate: (energy) {
                            setState(() {
                              _orbEnergy = energy;
                            });
                          },
                        )
                      ],
                    ),
                  ),
                  _LitImage(
                    color: orbColor,
                    imageSrc: 'assets/images/mg-base.png',
                    pulseEffect: _pulseEffect,
                    lightAmt: _finalReceiveLightAmt,
                  ),
                  _LitImage(
                    color: orbColor,
                    imageSrc: 'assets/images/mg-light-receive.png',
                    pulseEffect: _pulseEffect,
                    lightAmt: _finalReceiveLightAmt,
                  ),
                  _LitImage(
                    color: emitColor,
                    imageSrc: 'assets/images/mg-light-emit.png',
                    pulseEffect: _pulseEffect,
                    lightAmt: _finalEmitLightAmt,
                  ),
                  Positioned.fill(
                    child: IgnorePointer(
                      child: ParticleOverlay(
                        color: orbColor,
                        energy: _orbEnergy,
                      )
                    )
                  ),
                  Image.asset('assets/images/fg-base.png'),
                  _LitImage(
                    color: orbColor,
                    imageSrc: 'assets/images/fg-light-receive.png',
                    pulseEffect: _pulseEffect,
                    lightAmt: _finalReceiveLightAmt,
                  ),
                  _LitImage(
                    color: emitColor,
                    imageSrc: 'assets/images/fg-light-emit.png',
                    pulseEffect: _pulseEffect,
                    lightAmt: _finalEmitLightAmt,
                  ),
                  Positioned.fill(
                    child: TitleScreenUI(
                      difficulty: _difficulty,
                      onDifficultyFocused: _handleDifficultyFocused,
                      onDifficultyPressed: _handleDifficultyPressed,
                      onStartPressed: _handleStartPressed,
                    ),
                  )
                ],
              ).animate().fadeIn(
                    duration: const Duration(seconds: 1),
                    delay: const Duration(milliseconds: 300),
                  );
            },
          ),
        ),
      ),
    );
  }
}

class _LitImage extends StatelessWidget {
  const _LitImage({
    required this.color,
    required this.imageSrc,
    required this.pulseEffect,
    required this.lightAmt,
  });

  final Color color;
  final String imageSrc;
  final AnimationController pulseEffect;
  final double lightAmt;

  @override
  Widget build(BuildContext context) {
    final hsl = HSLColor.fromColor(color);
    return ListenableBuilder(
        listenable: pulseEffect,
        builder: (context, child) {
          return Image.asset(
            imageSrc,
            color: hsl.withLightness(lightAmt * hsl.lightness).toColor(),
            colorBlendMode: BlendMode.modulate,
          );
        });
  }
}

class _AnimatedColor extends StatelessWidget {
  const _AnimatedColor({
    required this.emitColor,
    required this.orbColor,
    required this.builder,
  });

  final Color emitColor;
  final Color orbColor;
  final Widget Function(BuildContext, Color orbColor, Color emitColor) builder;

  @override
  Widget build(BuildContext context) {
    return TweenAnimationBuilder<Color?>(
      tween: ColorTween(begin: emitColor, end: orbColor),
      duration: const Duration(milliseconds: 500),
      builder: (_, emitColor, child) {
        return TweenAnimationBuilder<Color?>(
          tween: ColorTween(begin: orbColor, end: emitColor),
          duration: const Duration(milliseconds: 500),
          builder: (_, orbColor, child) {
            return builder(context, orbColor!, emitColor!);
          },
        );
      },
    );
  }
}

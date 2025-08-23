import 'package:extra_alignments/extra_alignments.dart';
import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:focusable_control_builder/focusable_control_builder.dart';
import 'package:gap/gap.dart';
import 'package:provider/provider.dart';

import 'animated_sampler.dart';
import 'styles.dart';
import 'ticking_builder.dart';
import 'types.dart';
import 'ui_scalar.dart';

class TitleScreenUI extends StatelessWidget {
  const TitleScreenUI({
    super.key,
    required this.difficulty,
    required this.onDifficultyPressed,
    required this.onDifficultyFocused,
    required this.onStartPressed,
  });
  final int difficulty;
  final void Function(int difficulty) onDifficultyPressed;
  final void Function(int? difficulty) onDifficultyFocused;
  final VoidCallback onStartPressed;

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 40, horizontal: 50),
      child: Stack(
        children: <Widget>[
          const TopLeft(
            child: UIScaler(
              alignment: Alignment.topLeft,
              child: _TitleText(),
            ),
          ),
          BottomLeft(
            child: UIScaler(
              alignment: Alignment.bottomLeft,
              child: _DifficultyBtns(
                difficulty: difficulty,
                onDifficultyPressed: onDifficultyPressed,
                onDifficultyFocused: onDifficultyFocused,
              ),
            ),
          ),
          BottomRight(
            child: UIScaler(
              alignment: Alignment.bottomRight,
              child: Padding(
                padding: const EdgeInsets.only(bottom: 20, right: 40),
                child: _StartBtn(onPressed: () {}),
              ),
            ),
          ),
        ],
      ),
    );
  }
}

class _TitleText extends StatelessWidget {
  const _TitleText();

  @override
  Widget build(BuildContext context) {
    final content = _buildContent();
    return Consumer<FragmentPrograms?>(
      builder:
          (BuildContext context, FragmentPrograms? fragmentPrograms, child) {
        if (fragmentPrograms == null) {
          return content;
        }
        return TickingBuilder(
          builder: (BuildContext context, time) {
            return AnimatedSampler(
              builder: (image, size, canvas) {
                const double overdrawPx = 30;
                final shader = fragmentPrograms.ui.fragmentShader();
                shader
                  ..setFloat(0, size.width)
                  ..setFloat(1, size.height)
                  ..setFloat(2, time)
                  ..setImageSampler(0, image);

                Rect rect = Rect.fromLTRB(-overdrawPx, -overdrawPx,
                    size.width + overdrawPx, size.height + overdrawPx);
                canvas.drawRect(rect, Paint()..shader = shader);
              },
              child: content,
            );
          },
        );
      },
    );
  }

  Column _buildContent() {
    return Column(
      mainAxisSize: MainAxisSize.min,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        const Gap(20),
        Row(
          mainAxisSize: MainAxisSize.min,
          children: [
            Transform.translate(
              offset: Offset(-(TextStyles.h1.letterSpacing! * .5), 0),
              child: Text('OUTPOST', style: TextStyles.h1),
            ),
            Image.asset('assets/images/select-left.png', height: 65),
            Text('57', style: TextStyles.h2),
            Image.asset('assets/images/select-right.png', height: 65),
          ],
        ).animate().fadeIn(delay: .8.seconds, duration: .7.seconds),
        Text('INTO THE UNKNOWN', style: TextStyles.h3)
            .animate()
            .fadeIn(delay: 1.seconds, duration: .7.seconds),
      ],
    );
  }
}

class _DifficultyBtns extends StatelessWidget {
  const _DifficultyBtns({
    required this.difficulty,
    required this.onDifficultyPressed,
    required this.onDifficultyFocused,
  });

  final int difficulty;
  final void Function(int difficulty) onDifficultyPressed;
  final void Function(int? difficulty) onDifficultyFocused;

  @override
  Widget build(BuildContext context) {
    const duration = Duration(milliseconds: 350);
    return Column(
      mainAxisSize: MainAxisSize.min,
      children: [
        _DifficultyBtn(
          label: 'Casual',
          selected: difficulty == 0,
          onPressed: () => onDifficultyPressed(0),
          onHover: (over) => onDifficultyFocused(over ? 0 : null),
        ).animate().fadeIn(
              delay: const Duration(milliseconds: 1300),
              duration: duration,
            ),
        _DifficultyBtn(
          label: 'Normal',
          selected: difficulty == 1,
          onPressed: () => onDifficultyPressed(1),
          onHover: (over) => onDifficultyFocused(over ? 1 : null),
        ).animate().fadeIn(
              delay: const Duration(milliseconds: 1500),
              duration: duration,
            ),
        _DifficultyBtn(
          label: 'Hardcore',
          selected: difficulty == 2,
          onPressed: () => onDifficultyPressed(2),
          onHover: (over) => onDifficultyFocused(over ? 2 : null),
        ).animate().fadeIn(
              delay: const Duration(milliseconds: 1700),
              duration: duration,
            ),
        const Gap(20),
      ],
    );
  }
}

class _DifficultyBtn extends StatelessWidget {
  const _DifficultyBtn({
    required this.selected,
    required this.onPressed,
    required this.onHover,
    required this.label,
  });
  final String label;
  final bool selected;
  final VoidCallback onPressed;
  final void Function(bool hasFocus) onHover;

  @override
  Widget build(BuildContext context) {
    return FocusableControlBuilder(
      onPressed: onPressed,
      onHoverChanged: (_, state) => onHover.call(state.isHovered),
      builder: (_, state) {
        return Padding(
          padding: const EdgeInsets.all(8.0),
          child: SizedBox(
            width: 250,
            height: 60,
            child: Stack(
              children: [
                /// Bg with fill and outline
                AnimatedOpacity(
                  opacity: (!selected && (state.isHovered || state.isFocused))
                      ? 1
                      : 0,
                  duration: const Duration(milliseconds: 300),
                  child: Container(
                    decoration: BoxDecoration(
                      color: const Color(0xFF00D1FF).withOpacity(.1),
                      border: Border.all(color: Colors.white, width: 5),
                    ),
                  ),
                ),

                if (state.isHovered || state.isFocused) ...[
                  Container(
                    decoration: BoxDecoration(
                      color: const Color(0xFF00D1FF).withOpacity(.1),
                    ),
                  ),
                ],

                /// cross-hairs (selected state)
                if (selected) ...[
                  CenterLeft(
                    child: Image.asset('assets/images/select-left.png'),
                  ),
                  CenterRight(
                    child: Image.asset('assets/images/select-right.png'),
                  ),
                ],

                /// Label
                Center(
                  child: Text(label.toUpperCase(), style: TextStyles.btn),
                ),
              ],
            ),
          ),
        );
      },
    );
  }
}

class _StartBtn extends StatefulWidget {
  const _StartBtn({required this.onPressed});
  final VoidCallback onPressed;

  @override
  State<_StartBtn> createState() => _StartBtnState();
}

class _StartBtnState extends State<_StartBtn> {
  AnimationController? _btnAnim;
  bool _wasHovered = false;

  @override
  Widget build(BuildContext context) {
    return FocusableControlBuilder(
      cursor: SystemMouseCursors.click,
      onPressed: widget.onPressed,
      builder: (_, state) {
        if ((state.isHovered || state.isFocused) &&
            !_wasHovered &&
            _btnAnim?.status != AnimationStatus.forward) {
          _btnAnim?.forward(from: 0);
        }
        _wasHovered = (state.isHovered || state.isFocused);
        return SizedBox(
          width: 520,
          height: 100,
          child: Stack(
            children: [
              Positioned.fill(
                  child: Image.asset('assets/images/button-start.png')),
              if (state.isHovered || state.isFocused) ...[
                Positioned.fill(
                    child: Image.asset('assets/images/button-start-hover.png')),
              ],
              Center(
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.end,
                  children: [
                    Text(
                      'START MISSION',
                      style: TextStyles.btn
                          .copyWith(fontSize: 24, letterSpacing: 18),
                    ),
                  ],
                ),
              ),
            ],
          )
              .animate(autoPlay: false, onInit: (c) => _btnAnim = c)
              .shimmer(duration: 0.7.seconds, color: Colors.black),
        )
            .animate()
            .fadeIn(delay: 2.3.seconds)
            .slide(begin: const Offset(0, 2.0));
      },
    );
  }
}

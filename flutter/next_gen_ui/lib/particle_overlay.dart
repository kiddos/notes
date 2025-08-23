import 'dart:math';

import 'package:flutter/material.dart';
import 'package:particle_field/particle_field.dart';
import 'package:rnd/rnd.dart';

class ParticleOverlay extends StatelessWidget {
  const ParticleOverlay({
    super.key,
    required this.color,
    required this.energy,
  });

  final Color color;
  final double energy;

  @override
  Widget build(BuildContext context) {
    return ParticleField(
      spriteSheet: SpriteSheet(
        image: const AssetImage('assets/images/particle-wave.png'),
      ),
      blendMode: BlendMode.dstIn,
      onTick: (controller, _, size) {
        List<Particle> particles = controller.particles;

        double a = rnd(pi * 2);
        double dist = rnd(1, 4) * 35 + 150 * energy;
        double vel = rnd(1, 2) * (1 + energy * 1.8);
        double scale = rnd(1, 2) * 0.6 + energy * 0.5;
        particles.add(Particle(
          lifespan: rnd(1, 2) * 20 + energy * 15,
          x: cos(a) * dist,
          y: sin(a) * dist,
          vx: cos(a) * vel,
          vy: sin(a) * vel,
          rotation: a,
          scale: scale,
        ));

        particles = particles.where((p) => p.lifespan > 0).toList();
        const double acc = 1.025;
        for (Particle p in particles) {
          p.update(
            scale: p.scale * acc,
            vx: p.vx * acc,
            vy: p.vy * acc,
            color: color.withOpacity(p.lifespan * 0.001 + 0.01),
            lifespan: p.lifespan - 1,
          );
        }
        controller.particles = particles;
      },
    );
  }
}

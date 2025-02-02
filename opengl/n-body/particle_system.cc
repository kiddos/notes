#include "particle_system.h"

ParticleSystem::ParticleSystem(std::vector<Particle>& particles)
    : size_(particles.size()),
      pos_(particles.size()),
      vel_(particles.size()),
      accel_(particles.size()),
      masses_(particles.size()),
      forces_(particles.size()) {
  for (int i = 0; i < (int)size_; ++i) {
    pos_[i] = particles[i].position;
    vel_[i] = particles[i].velocity;
    accel_[i] = particles[i].acceleration;
    masses_[i] = glm::vec4(particles[i].mass, 0, 0, 0);
    forces_[i] = glm::vec4(0.f);
  }
}

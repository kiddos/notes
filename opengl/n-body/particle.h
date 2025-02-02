#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>
#include <ostream>

struct Particle {
  glm::vec4 position;
  glm::vec4 velocity;
  glm::vec4 acceleration;
  float mass;

  Particle() = default;
  Particle(glm::vec3 pos, glm::vec3 vel, float mass);
  Particle(glm::vec3 pos, glm::vec3 vel, glm::vec3 acc, float mass);

  inline void set_velocity(glm::vec3 vel) { velocity = glm::vec4(vel, 0.f); }
};

std::ostream& operator<<(std::ostream& os, const Particle& p);

#endif /* end of include guard: PARTICLE_H */

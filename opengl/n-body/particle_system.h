#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <vector>

#include "particle.h"

class ParticleSystem {
 public:
  ParticleSystem(std::vector<Particle>& particles);
  inline unsigned int size() const { return size_; }
  inline std::vector<glm::vec4>& get_position() { return pos_; }
  inline std::vector<glm::vec4>& get_velocities() { return vel_; }
  inline std::vector<glm::vec4>& get_acceleration() { return accel_; }
  inline std::vector<glm::vec4>& get_masses() { return masses_; }
  inline std::vector<glm::vec4>& get_forces() { return forces_; }

 private:
  size_t size_;
  std::vector<glm::vec4> pos_;
  std::vector<glm::vec4> vel_;
  std::vector<glm::vec4> accel_;
  std::vector<glm::vec4> masses_;
  std::vector<glm::vec4> forces_;
};

#endif /* end of include guard: PARTICLE_SYSTEM_H */

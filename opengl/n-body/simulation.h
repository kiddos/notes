#ifndef SIMULATION_H
#define SIMULATION_H

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/random.hpp>
#include <memory>
#include <string>
#include <vector>

#include "particle_system.h"

class Simulation {
 public:
  Simulation(glm::vec3 world, int particle_count);

  void Draw();
  void Update(float dt);

 private:
  std::vector<Particle> Initialize(glm::vec3 world, int count);
  std::string ReadFile(const std::string& filepath);
  std::pair<GLuint, bool> CompileShader(GLuint shaderType, const char* code);
  void PrepareShader();
  inline glm::mat4 model() const { return glm::mat4(1.f); }
  inline glm::mat4 view() const { return glm::lookAt(position_, center_, up_); }
  inline glm::mat4 projection() const {
    return glm::perspective(glm::radians(fov_), aspect_, znear_, zfar_);
  }

  void SyncData();

  glm::vec3 world_;
  std::unique_ptr<ParticleSystem> system_;
  glm::vec3 position_;
  glm::vec3 center_;
  glm::vec3 up_;
  float fov_;
  float aspect_;
  float znear_;
  float zfar_;
  GLuint program_;
  GLuint VAO_;
  GLuint pos_SSBO_, vel_SSBO_;
};

#endif /* end of include guard: SIMULATION_H */

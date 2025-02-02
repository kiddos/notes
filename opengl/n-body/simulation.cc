#include "simulation.h"

#include <GL/glew.h>

#include <fstream>
#include <iostream>
#include <sstream>

Simulation::Simulation(glm::vec3 world, int particle_count) : world_(world) {
  std::vector<Particle> particles = Initialize(world, particle_count);
  system_ = std::make_unique<ParticleSystem>(particles);

  PrepareShader();
  position_ = glm::vec3(0.0f, 0.0f, world.z * 1.0f);
  center_ = glm::vec3(0.0f, 0.0f, 0.0f);
  up_ = glm::vec3(0.0f, 1.0f, 0.0f);

  fov_ = 90.0;
  aspect_ = 4.0f / 3.0f;
  znear_ = 0.1f;
  zfar_ = world.z * 100.0f;
}

void Simulation::Draw() {
  // glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glClearColor(0.f, 0.f, 0.f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glUseProgram(program_);
  auto model_mat = model();
  auto view_mat = view();
  auto projection_mat = projection();

  glUniformMatrix4fv(glGetUniformLocation(program_, "u_model"), 1, GL_FALSE,
                     &model_mat[0][0]);
  glUniformMatrix4fv(glGetUniformLocation(program_, "u_view"), 1, GL_FALSE,
                     &view_mat[0][0]);
  glUniformMatrix4fv(glGetUniformLocation(program_, "u_projection"), 1,
                     GL_FALSE, &projection_mat[0][0]);

  glUniform3fv(glGetUniformLocation(program_, "u_cameraPos"), 1, &position_[0]);
  glUniform1f(glGetUniformLocation(program_, "u_worldSize"),
              glm::length(world_));
  glDrawArrays(GL_POINTS, 0, system_->size());
}

void Simulation::Update(float dt) {
  int n = system_->size();
  for (int i = 0; i < n; ++i) {
    glm::vec4 total(0.f);
    for (int j = 0; j < n; ++j) {
      auto vector_i_j = system_->get_position()[j] - system_->get_position()[i];
      const float distance_i_j = std::pow(glm::length(vector_i_j) + 1e-5, 1.5);
      if (distance_i_j > 0) {
        total += ((0.006f * system_->get_masses()[j].x) / distance_i_j) * vector_i_j;
      }
    }
    system_->get_forces()[i] = total;
  }

  for (int i = 0; i < n; ++i) {
    system_->get_velocities()[i] += system_->get_acceleration()[i] * dt * 0.5f;
    system_->get_position()[i] += system_->get_velocities()[i] * dt;
    system_->get_acceleration()[i] = system_->get_forces()[i];
    system_->get_velocities()[i] += system_->get_acceleration()[i] * dt * 0.5f;
  }

  glm::vec4 center(0);
  for (int i = 0; i < n; ++i) {
    center += system_->get_position()[i];
  }
  center /= n;
  center_ = glm::vec4(center.x, center.y, center.z, 1.0);
  // auto p = system_->get_velocities()[0];
  // std::cout << center.x << " " << center.y << " " << center.z << std::endl;
  // std::cout << p.x << " " << p.y << " " << p.z << std::endl;

  SyncData();
}

std::vector<Particle> Simulation::Initialize(glm::vec3 world, int count) {
  std::vector<Particle> particles(count);

  float length = glm::length(world) / 20.0f;
  float radius = glm::length(world) / 3.0f;
  float volume = world.x * world.y * world.z;
  for (int i = 0; i < count; ++i) {
    glm::vec3 position = glm::ballRand(radius);
    // glm::vec3 position = glm::vec4(0);
    glm::vec3 initialVel =
        (world.z == 0) ? glm::linearRand(glm::vec3(-length, -length, 0.f),
                                         glm::vec3(length, length, 0.f))
                       : glm::linearRand(glm::vec3(-length, -length, -length),
                                         glm::vec3(length, length, length));
    particles[i] = Particle(position, initialVel, volume / count);
  }
  return particles;
}

std::string Simulation::ReadFile(const std::string& filepath) {
  std::ifstream file(filepath);
  if (!file.is_open()) {
    throw std::runtime_error("Fail to open file: " + filepath);
  }

  std::stringstream stream;
  stream << file.rdbuf();
  file.close();
  return stream.str();
}

std::pair<GLuint, bool> Simulation::CompileShader(GLuint shaderType,
                                                  const char* code) {
  GLuint shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &code, nullptr);
  glCompileShader(shader);

  int success = 0;
  char infolog[1024];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, sizeof(infolog), nullptr, infolog);
    std::cerr << "Fail to compile shader:\n" << infolog << std::endl;
    return {shader, false};
  }
  return {shader, true};
}

void Simulation::PrepareShader() {
  std::cout << "prepare shader..." << std::endl;
  std::string vertex_shader = ReadFile("./shaders/vertex_shader.glsl");
  std::string fragment_shader = ReadFile("./shaders/fragment_shader.glsl");
  auto [vertex, s1] = CompileShader(GL_VERTEX_SHADER, vertex_shader.c_str());
  auto [fragment, s2] =
      CompileShader(GL_FRAGMENT_SHADER, fragment_shader.c_str());

  glEnable(GL_PROGRAM_POINT_SIZE);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  if (s1 && s2) {
    program_ = glCreateProgram();
    glAttachShader(program_, vertex);
    glAttachShader(program_, fragment);
    glLinkProgram(program_);

    int success = 0;
    char infolog[1024];
    glGetProgramiv(program_, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(program_, sizeof(infolog), nullptr, infolog);
      std::cerr << "Fail to link shader" << infolog << std::endl;
    }

    // Delete shaders
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    glUseProgram(program_);

    glGenVertexArrays(1, &VAO_);
    glBindVertexArray(VAO_);

    glGenBuffers(1, &pos_SSBO_);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, this->pos_SSBO_);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, this->pos_SSBO_);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(glm::vec4) * system_->size(),
                 &system_->get_position()[0], GL_DYNAMIC_DRAW);

    glGenBuffers(1, &vel_SSBO_);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, this->vel_SSBO_);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, this->vel_SSBO_);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(glm::vec4) * system_->size(),
                 &system_->get_velocities()[0], GL_DYNAMIC_DRAW);
  }
}

void Simulation::SyncData() {
  glBindBuffer(GL_SHADER_STORAGE_BUFFER, pos_SSBO_);
  glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, sizeof(glm::vec4) * system_->size(), &system_->get_position()[0]);

  glBindBuffer(GL_SHADER_STORAGE_BUFFER, vel_SSBO_);
  glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, sizeof(glm::vec4) * system_->size(), &system_->get_velocities()[0]);

  glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
}

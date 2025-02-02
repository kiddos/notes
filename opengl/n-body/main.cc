#include <GL/glew.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include <chrono>
#include <iostream>

#include "simulation.h"
#include "window.h"

int main(void) {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
    return -1;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  Window window(800, 600, "n body");

  glm::vec3 world(6.0, 6.0, 6.0);
  int particle_count = 200;
  Simulation simulation(world, particle_count);

  using namespace std::chrono;
  auto last_time = high_resolution_clock::now();
  auto start_time = high_resolution_clock::now();
  size_t frames = 0;
  while (window.running()) {
    window.PollEvents();
    simulation.Draw();
    window.Render();

    auto current_time = high_resolution_clock::now();
    frames++;

    duration<float> dt = duration_cast<duration<float>>(current_time - last_time);
    last_time = current_time;

    simulation.Update(dt.count());
    duration<float> total = duration_cast<duration<float>>(current_time - start_time);
    float fps = frames / total.count();
    std::cout << fps << "\r" << std::flush;
  }

  SDL_Quit();
  return 0;
}

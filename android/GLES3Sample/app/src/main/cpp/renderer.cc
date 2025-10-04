#include <cstring>

#include "renderer.h"

Renderer::Renderer() = default;

Renderer::~Renderer() = default;

void Renderer::resize(int w, int h) {
  glViewport(0, 0, w, h);
}

void Renderer::render() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  draw();
}
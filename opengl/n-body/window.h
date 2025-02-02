#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>

#include <string>

class Window {
 public:
  Window(int width, int height, const std::string& title);
  ~Window();

  inline bool running() const { return running_; }
  void Render();
  void PollEvents();

 private:
  std::string title_;
  SDL_Window* window_;
  SDL_Renderer* renderer_;
  SDL_GLContext gl_context_;
  bool running_;
};

#endif /* end of include guard: WINDOW_H */

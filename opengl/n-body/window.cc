#include "window.h"

Window::Window(int width, int height, const std::string& title)
    : title_(title), window_(nullptr), renderer_(nullptr), running_(true) {
  if (!SDL_CreateWindowAndRenderer(title_.c_str(), width, height, 0, &window_,
                                   &renderer_)) {
    SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
    return;
  }

  gl_context_ = SDL_GL_CreateContext(window_);
  SDL_GL_MakeCurrent(window_, gl_context_);
  SDL_GL_SetSwapInterval(1);  // Enable vsync
  SDL_ShowWindow(window_);

  if (glewInit() != GLEW_OK) {
    running_ = false;
  }
}

Window::~Window() {
  SDL_GL_DestroyContext(gl_context_);
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
}

void Window::PollEvents() {
  SDL_Event e;
  if (SDL_PollEvent(&e)) {
    if (e.type == SDL_EVENT_QUIT ||
        (e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE)) {
      running_ = false;
    }
  }
}

void Window::Render() {
  SDL_GL_SwapWindow(window_);
}

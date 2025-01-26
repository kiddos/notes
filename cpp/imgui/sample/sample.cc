#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl3.h>

#include <iostream>

static SDL_Window* window;
static bool done = false;
static SDL_GLContext gl_context;
static bool show_demo_window = true;
static bool window1 = true;
static bool window2 = true;

void PollEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    ImGui_ImplSDL3_ProcessEvent(&event);
    if (event.type == SDL_EVENT_QUIT) done = true;
    if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED &&
        event.window.windowID == SDL_GetWindowID(window))
      done = true;
  }
  if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) {
    SDL_Delay(10);
  }
}

void Window1() {
  if (window1) {
    ImGui::Begin("Window1", &window1);
    ImGui::End();
  }
}

void Window2() {
  if (window2) {
    ImGui::Begin("Window2", &window2);
    ImGui::End();
  }
}

void UpdateFrame() {
  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplSDL3_NewFrame();
  ImGui::NewFrame();

  if (show_demo_window) {
    ImGui::ShowDemoWindow(&show_demo_window);
  }

  Window1();
  Window2();

  // Rendering
  ImGui::Render();
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  SDL_GL_SwapWindow(window);
}

int main(void) {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
    std::cerr << "Error: SDL_Init(): " << SDL_GetError() << std::endl;
    return -1;
  }

  const char* glsl_version = "#version 130";
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

  int window_flags =
      SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
  int width = 800;
  int height = 600;
  window = SDL_CreateWindow("Dear ImGui SDL3+OpenGL3 example", width, height,
                            window_flags);

  gl_context = SDL_GL_CreateContext(window);

  SDL_GL_MakeCurrent(window, gl_context);
  SDL_GL_SetSwapInterval(1);  // Enable vsync
  SDL_ShowWindow(window);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  // Enable Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  // Enable Gamepad Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
  // io.Fonts->AddFontFromFileTTF("../ComicNeue-Regular.ttf", 18.0f);

  // Setup Dear ImGui style
  // ImGui::StyleColorsDark();
  ImGui::StyleColorsLight();

  // Setup Platform/Renderer backends
  ImGui_ImplSDL3_InitForOpenGL(window, gl_context);
  ImGui_ImplOpenGL3_Init(glsl_version);

  while (!done) {
    PollEvents();
    UpdateFrame();
  }

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplSDL3_Shutdown();

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

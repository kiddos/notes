#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;
static bool running = true;

void UpdateEvent() {
  SDL_Event e;
  if (SDL_PollEvent(&e)) {
    if (e.type == SDL_EVENT_QUIT ||
        (e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE)) {
      running = false;
    }
  }
}

void MainLoop() {
  const double now = ((double)SDL_GetTicks()) / 1000.0;
  const float red = (float)(0.5 + 0.5 * SDL_sin(now));
  const float green = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
  const float blue = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));
  SDL_SetRenderDrawColorFloat(renderer, red, green, blue,
                              SDL_ALPHA_OPAQUE_FLOAT);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

int main(void) {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
    return -1;
  }

  if (!SDL_CreateWindowAndRenderer("sample", 640, 480, 0, &window, &renderer)) {
    SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  while (running) {
    UpdateEvent();
    MainLoop();
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

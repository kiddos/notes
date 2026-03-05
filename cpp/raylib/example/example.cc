#include <raylib.h>
#include <stddef.h>

#include <vector>

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 450;
constexpr float PLAYER_SIZE = 20.0f;
constexpr float PLAYER_SPEED = 5.0f;
constexpr int NUM_OBSTACLES = 5;

Vector2 player_position;
float player_radius;
Color player_color;
std::vector<Rectangle> obstacles_;
Color obstaacle_color;
float obstacle_speed;

bool game_over = false;
bool game_won = false;

void init_game() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Simple Game");

  player_position = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT - 50};
  player_radius = PLAYER_SIZE / 2;
  player_color = SKYBLUE;
  obstaacle_color = RED;
  obstacle_speed = 2.0f;

  for (int i = 0; i < NUM_OBSTACLES; i++) {
    Rectangle o;
    o.width = GetRandomValue(30, 80);
    o.height = GetRandomValue(20, 50);
    o.x = (float)GetRandomValue(SCREEN_WIDTH, SCREEN_WIDTH * 2);
    o.y = (float)GetRandomValue(0, SCREEN_HEIGHT - o.height);
    obstacles_.push_back(o);
  }
}

void update() {
  if (!game_over && !game_won) {
    // Player input
    if (IsKeyDown(KEY_RIGHT)) player_position.x += PLAYER_SPEED;
    if (IsKeyDown(KEY_LEFT)) player_position.x -= PLAYER_SPEED;
    if (IsKeyDown(KEY_UP)) player_position.y -= PLAYER_SPEED;
    if (IsKeyDown(KEY_DOWN)) player_position.y += PLAYER_SPEED;

    // Boundary checks for the player
    if (player_position.x - player_radius < 0)
      player_position.x = player_radius;
    if (player_position.x + player_radius > SCREEN_WIDTH)
      player_position.x = SCREEN_WIDTH - player_radius;
    if (player_position.y - player_radius < 0)
      player_position.y = player_radius;
    if (player_position.y + player_radius > SCREEN_HEIGHT)
      player_position.y = SCREEN_HEIGHT - player_radius;

    // Update obstacles position
    for (size_t i = 0; i < obstacles_.size(); i++) {
      obstacles_[i].x -= obstacle_speed;

      if (obstacles_[i].x + obstacles_[i].width < 0) {
        obstacles_[i].x = (float)GetRandomValue(SCREEN_WIDTH, SCREEN_WIDTH * 2);
        obstacles_[i].y =
            (float)GetRandomValue(0, SCREEN_HEIGHT - (int)obstacles_[i].height);
        obstacles_[i].width = GetRandomValue(30, 80);
        obstacles_[i].height = GetRandomValue(20, 50);
      }

      // Collision detection (Circle vs. Rectangle)
      if (CheckCollisionCircleRec(player_position, player_radius,
                                  obstacles_[i])) {
        game_over = true;
      }
    }

    // Check for game win condition (player reaches the top)
    if (player_position.y < 50) {
      game_won = true;
    }
  } else {
    // Restart game on Enter key press
    if (IsKeyPressed(KEY_ENTER)) {
      // Reset player and obstacle positions
      player_position =
          (Vector2){(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT - 50};
      for (size_t i = 0; i < obstacles_.size(); i++) {
        obstacles_[i].x = (float)GetRandomValue(SCREEN_WIDTH, SCREEN_WIDTH * 2);
        obstacles_[i].y =
            (float)GetRandomValue(0, SCREEN_HEIGHT - (int)obstacles_[i].height);
      }
      game_over = false;
      game_won = false;
    }
  }
}

void render() {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  // Draw game elements
  DrawCircleV(player_position, player_radius, player_color);
  for (size_t i = 0; i < obstacles_.size(); i++) {
    DrawRectangleRec(obstacles_[i], obstaacle_color);
  }

  // Draw game status text
  if (game_over) {
    DrawText("GAME OVER",
             GetScreenWidth() / 2 - MeasureText("GAME OVER", 20) / 2,
             GetScreenHeight() / 2, 20, BLACK);
    DrawText(
        "Press ENTER to Restart",
        GetScreenWidth() / 2 - MeasureText("Press ENTER to Restart", 20) / 2,
        GetScreenHeight() / 2 + 30, 20, BLACK);
  }
  if (game_won) {
    DrawText("YOU WIN!", GetScreenWidth() / 2 - MeasureText("YOU WIN!", 20) / 2,
             GetScreenHeight() / 2, 20, BLACK);
    DrawText(
        "Press ENTER to Restart",
        GetScreenWidth() / 2 - MeasureText("Press ENTER to Restart", 20) / 2,
        GetScreenHeight() / 2 + 30, 20, BLACK);
  }

  EndDrawing();
}

int main(void) {
  init_game();

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    update();

    render();
  }

  CloseWindow();
  return 0;
}

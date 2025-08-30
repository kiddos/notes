#include <raylib.h>

#include <vector>

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 450;
constexpr float PLAYER_SIZE = 20.0f;
constexpr float PLAYER_SPEED = 5.0f;
constexpr int NUM_OBSTACLES = 5;

class Game {
 public:
  Game() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Simple Game");
    init();
  }

  ~Game() { CloseWindow(); }

  void update() {
    if (!game_over_ && !game_won_) {
      // Player input
      if (IsKeyDown(KEY_RIGHT)) player_position_.x += PLAYER_SPEED;
      if (IsKeyDown(KEY_LEFT)) player_position_.x -= PLAYER_SPEED;
      if (IsKeyDown(KEY_UP)) player_position_.y -= PLAYER_SPEED;
      if (IsKeyDown(KEY_DOWN)) player_position_.y += PLAYER_SPEED;

      // Boundary checks for the player
      if (player_position_.x - player_radius_ < 0)
        player_position_.x = player_radius_;
      if (player_position_.x + player_radius_ > SCREEN_WIDTH)
        player_position_.x = SCREEN_WIDTH - player_radius_;
      if (player_position_.y - player_radius_ < 0)
        player_position_.y = player_radius_;
      if (player_position_.y + player_radius_ > SCREEN_HEIGHT)
        player_position_.y = SCREEN_HEIGHT - player_radius_;

      // Update obstacles position
      for (size_t i = 0; i < obstacles_.size(); i++) {
        obstacles_[i].x -= obstacle_speed_;

        if (obstacles_[i].x + obstacles_[i].width < 0) {
          obstacles_[i].x =
              (float)GetRandomValue(SCREEN_WIDTH, SCREEN_WIDTH * 2);
          obstacles_[i].y = (float)GetRandomValue(
              0, SCREEN_HEIGHT - (int)obstacles_[i].height);
          obstacles_[i].width = GetRandomValue(30, 80);
          obstacles_[i].height = GetRandomValue(20, 50);
        }

        // Collision detection (Circle vs. Rectangle)
        if (CheckCollisionCircleRec(player_position_, player_radius_,
                                    obstacles_[i])) {
          game_over_ = true;
        }
      }

      // Check for game win condition (player reaches the top)
      if (player_position_.y < 50) {
        game_won_ = true;
      }
    } else {
      // Restart game on Enter key press
      if (IsKeyPressed(KEY_ENTER)) {
        // Reset player and obstacle positions
        player_position_ =
            (Vector2){(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT - 50};
        for (size_t i = 0; i < obstacles_.size(); i++) {
          obstacles_[i].x =
              (float)GetRandomValue(SCREEN_WIDTH, SCREEN_WIDTH * 2);
          obstacles_[i].y = (float)GetRandomValue(
              0, SCREEN_HEIGHT - (int)obstacles_[i].height);
        }
        game_over_ = false;
        game_won_ = false;
      }
    }
  }

  void render() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Draw game elements
    DrawCircleV(player_position_, player_radius_, player_color_);
    for (size_t i = 0; i < obstacles_.size(); i++) {
      DrawRectangleRec(obstacles_[i], obstacle_color_);
    }

    // Draw game status text
    if (game_over_) {
      DrawText("GAME OVER",
               GetScreenWidth() / 2 - MeasureText("GAME OVER", 20) / 2,
               GetScreenHeight() / 2, 20, BLACK);
      DrawText(
          "Press ENTER to Restart",
          GetScreenWidth() / 2 - MeasureText("Press ENTER to Restart", 20) / 2,
          GetScreenHeight() / 2 + 30, 20, BLACK);
    }
    if (game_won_) {
      DrawText("YOU WIN!",
               GetScreenWidth() / 2 - MeasureText("YOU WIN!", 20) / 2,
               GetScreenHeight() / 2, 20, BLACK);
      DrawText(
          "Press ENTER to Restart",
          GetScreenWidth() / 2 - MeasureText("Press ENTER to Restart", 20) / 2,
          GetScreenHeight() / 2 + 30, 20, BLACK);
    }

    EndDrawing();
  }

  void main_loop() {
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
      update();

      render();
    }
  }

 private:
  Vector2 player_position_;
  float player_radius_;
  Color player_color_;
  std::vector<Rectangle> obstacles_;
  Color obstacle_color_;
  float obstacle_speed_;

  bool game_over_ = false;
  bool game_won_ = false;

  void init() {
    player_position_ = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT - 50};
    player_radius_ = PLAYER_SIZE / 2;
    player_color_ = SKYBLUE;
    obstacle_color_ = RED;
    obstacle_speed_ = 2.0f;

    for (int i = 0; i < NUM_OBSTACLES; i++) {
      Rectangle o;
      o.width = GetRandomValue(30, 80);
      o.height = GetRandomValue(20, 50);
      o.x = (float)GetRandomValue(SCREEN_WIDTH, SCREEN_WIDTH * 2);
      o.y = (float)GetRandomValue(0, SCREEN_HEIGHT - o.height);
      obstacles_.push_back(o);
    }
  }
};

int main(void) {
  Game game;
  game.main_loop();
  return 0;
}

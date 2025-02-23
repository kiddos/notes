#include "DEV_Config.h"
#include "GUI_Paint.h"
#include "LCD_1in8.h"
#include "pico/stdlib.h"

void draw(UWORD* image_data, int size, int start_row, int start_col,
          UWORD color) {
  int w = LCD_1IN8.WIDTH;
  for (int y = start_row; y < start_row + size; ++y) {
    for (int x = start_col; x < start_col + size; ++x) {
      Paint_SetPixel(x, y, color);
    }
  }
}

int main() {
  sleep_ms(100);
  stdio_init_all();

  if (DEV_Module_Init() != 0) {
    return -1;
  }
  LCD_1IN8_Init(HORIZONTAL);
  LCD_1IN8_Clear(0xFFFF);
  int w = LCD_1IN8.WIDTH;
  int h = LCD_1IN8.HEIGHT;
  int row_size = w * 2;
  UWORD image_data[w * h * 2];
  Paint_NewImage((UBYTE*)image_data, w, h, 0, WHITE);
  Paint_SetScale(65);
  Paint_Clear(WHITE);

  draw(image_data, 30, 0, 0, RED);
  draw(image_data, 30, 30, 0, GREEN);
  draw(image_data, 30, 60, 0, BLUE);
  while (true) {
    sleep_ms(100);
    LCD_1IN8_Display(image_data);
  }

  DEV_Module_Exit();
  return 0;
}

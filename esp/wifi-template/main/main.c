#include <sys/time.h>

#include "esp_netif.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "board_info.h"
#include "wifi_init.h"
#include "webserver.h"

void main_loop() {
  // TODO
}

void app_main() {
  board_info_show();

  ESP_ERROR_CHECK(nvs_flash_init());
  ESP_ERROR_CHECK(esp_netif_init());

  while (1) {
    ESP_LOGI(TAG, "wifi init sta...");
    ESP_ERROR_CHECK(wifi_init_sta());

    ESP_LOGI(TAG, "start main loop...");
    while (webserver_get()) {
      main_loop();
      vTaskDelay(pdMS_TO_TICKS(CONFIG_MAIN_LOOP_PERIOD));
    }
    vTaskDelay(pdMS_TO_TICKS(100000));
  }
}

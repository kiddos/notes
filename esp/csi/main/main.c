#include <stdio.h>

#include "esp_csi_gain_ctrl.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "ping/ping_sock.h"
#include "rom/ets_sys.h"
#include "wifi_config.h"

#if CONFIG_IDF_TARGET_ESP32S3 || CONFIG_IDF_TARGET_ESP32C3 || \
    CONFIG_IDF_TARGET_ESP32C5 || CONFIG_IDF_TARGET_ESP32C6 || \
    CONFIG_IDF_TARGET_ESP32C61
#define CONFIG_GAIN_CONTROL 1
#endif

#define CONFIG_SEND_FREQUENCY 100

static EventGroupHandle_t s_wifi_event_group;
static int s_retry_num = 0;
static esp_netif_t *s_example_sta_netif = NULL;

static const char* TAG = "wifi";

static void wifi_csi_init();

static void wifi_csi_rx_cb(void* ctx, wifi_csi_info_t* info) {
  if (!info || !info->buf) {
    ESP_LOGW(TAG, "<%s> wifi_csi_cb", esp_err_to_name(ESP_ERR_INVALID_ARG));
    return;
  }

  if (memcmp(info->mac, ctx, 6)) {
    return;
  }

  const wifi_pkt_rx_ctrl_t* rx_ctrl = &info->rx_ctrl;
  static int s_count = 0;
  float compensate_gain = 1.0f;
  static uint8_t agc_gain = 0;
  static int8_t fft_gain = 0;
#if CONFIG_GAIN_CONTROL
  static uint8_t agc_gain_baseline = 0;
  static int8_t fft_gain_baseline = 0;
  esp_csi_gain_ctrl_get_rx_gain(rx_ctrl, &agc_gain, &fft_gain);
  if (s_count < 100) {
    esp_csi_gain_ctrl_record_rx_gain(agc_gain, fft_gain);
  } else if (s_count == 100) {
    esp_csi_gain_ctrl_get_rx_gain_baseline(&agc_gain_baseline,
                                           &fft_gain_baseline);
#if CONFIG_FORCE_GAIN
    esp_csi_gain_ctrl_set_rx_force_gain(agc_gain_baseline, fft_gain_baseline);
    ESP_LOGI(TAG, "fft_force %d, agc_force %d", fft_gain_baseline,
             agc_gain_baseline);
#endif
  }
  esp_csi_gain_ctrl_get_gain_compensation(&compensate_gain, agc_gain, fft_gain);
  ESP_LOGD(TAG, "compensate_gain %f, agc_gain %d, fft_gain %d", compensate_gain,
           agc_gain, fft_gain);
#endif

  if (!s_count) {
    ESP_LOGI(TAG, "================ CSI RECV ================");
    ets_printf(
        "type,id,mac,rssi,rate,sig_mode,mcs,bandwidth,smoothing,not_sounding,"
        "aggregation,stbc,fec_coding,sgi,noise_floor,ampdu_cnt,channel,"
        "secondary_channel,local_timestamp,ant,sig_len,rx_state,len,first_word,"
        "data\n");
  }
  ets_printf("CSI_DATA,%d," MACSTR
             ",%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
             s_count, MAC2STR(info->mac), rx_ctrl->rssi, rx_ctrl->rate,
             rx_ctrl->sig_mode, rx_ctrl->mcs, rx_ctrl->cwb, rx_ctrl->smoothing,
             rx_ctrl->not_sounding, rx_ctrl->aggregation, rx_ctrl->stbc,
             rx_ctrl->fec_coding, rx_ctrl->sgi, rx_ctrl->noise_floor,
             rx_ctrl->ampdu_cnt, rx_ctrl->channel, rx_ctrl->secondary_channel,
             rx_ctrl->timestamp, rx_ctrl->ant, rx_ctrl->sig_len,
             rx_ctrl->rx_state);

  ets_printf(",%d,%d,\"[%d", info->len, info->first_word_invalid,
             (int16_t)(compensate_gain * info->buf[0]));
  for (int i = 1; i < info->len; i++) {
    ets_printf(",%d", (int16_t)(compensate_gain * info->buf[i]));
  }
  ets_printf("]\"\n");
  s_count++;
}

static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data) {
  if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
    esp_wifi_connect();
  } else if (event_base == WIFI_EVENT &&
             event_id == WIFI_EVENT_STA_DISCONNECTED) {
    if (s_retry_num < CONFIG_ESP_MAXIMUM_RETRY) {
      esp_wifi_connect();
      s_retry_num++;
      ESP_LOGI(TAG, "retry to connect to the AP");
    } else {
      xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
    }
    ESP_LOGI(TAG, "connect to the AP fail");
  } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
    ip_event_got_ip_t* event = (ip_event_got_ip_t*)event_data;
    ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
    s_retry_num = 0;
    xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
  }
}

esp_err_t wifi_init_sta(void) {
  s_wifi_event_group = xEventGroupCreate();

  // esp_netif_create_default_wifi_sta();

  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&cfg));

  esp_netif_inherent_config_t esp_netif_config = ESP_NETIF_INHERENT_DEFAULT_WIFI_STA();
  // Warning: the interface desc is used in tests to capture actual connection details (IP, gw, mask)
  esp_netif_config.if_desc = "csi_description";
  esp_netif_config.route_prio = 128;
  s_example_sta_netif = esp_netif_create_wifi(WIFI_IF_STA, &esp_netif_config);
  esp_wifi_set_default_wifi_sta_handlers();


  esp_event_handler_instance_t instance_any_id;
  esp_event_handler_instance_t instance_got_ip;
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL,
      &instance_any_id));
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      IP_EVENT, IP_EVENT_STA_GOT_IP, &wifi_event_handler, NULL,
      &instance_got_ip));

  wifi_config_t wifi_config = {
      .sta =
          {
              .ssid = CONFIG_ESP_WIFI_SSID,
              .password = CONFIG_ESP_WIFI_PASSWORD,
              .threshold.authmode = ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD,
              .sae_pwe_h2e = ESP_WIFI_SAE_MODE,
              .sae_h2e_identifier = "",
          },
  };
  ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
  ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_start());

  xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTING_BIT);

  EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
                                         WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                         pdFALSE, pdFALSE, portMAX_DELAY);
  ESP_LOGI(TAG, "wifi_init_sta finished.");

  if (bits & WIFI_CONNECTED_BIT) {
    ESP_LOGI(TAG, "connected to ap SSID:%s password:%s", CONFIG_ESP_WIFI_SSID,
             CONFIG_ESP_WIFI_PASSWORD);
    return ESP_OK;
  } else if (bits & WIFI_FAIL_BIT) {
    ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
             CONFIG_ESP_WIFI_SSID, CONFIG_ESP_WIFI_PASSWORD);
  } else {
    ESP_LOGE(TAG, "UNEXPECTED EVENT");
  }
  return ESP_FAIL;
}

static void wifi_csi_init() {
  ESP_LOGI(TAG, "csi init...");
  wifi_csi_config_t csi_config = {
      .lltf_en = true,
      .htltf_en = false,
      .stbc_htltf2_en = false,
      .ltf_merge_en = true,
      .channel_filter_en = true,
      .manu_scale = true,
      .shift = true,
  };
  static wifi_ap_record_t s_ap_info = {0};
  ESP_ERROR_CHECK(esp_wifi_sta_get_ap_info(&s_ap_info));
  esp_err_t err = esp_wifi_set_csi_config(&csi_config);
  ESP_LOGI(TAG, "CSI config: %s", esp_err_to_name(err));
  ESP_ERROR_CHECK(esp_wifi_set_csi_rx_cb(wifi_csi_rx_cb, s_ap_info.bssid));
  ESP_ERROR_CHECK(esp_wifi_set_csi(true));
}

static esp_err_t wifi_ping_router_start() {
  static esp_ping_handle_t ping_handle = NULL;

  esp_ping_config_t ping_config = ESP_PING_DEFAULT_CONFIG();
  ping_config.count = 0;
  ping_config.interval_ms = 1000 / CONFIG_SEND_FREQUENCY;
  ping_config.task_stack_size = 3072;
  ping_config.data_size = 1;

  esp_netif_ip_info_t local_ip;
  esp_netif_get_ip_info(esp_netif_get_handle_from_ifkey("WIFI_STA_DEF"),
                        &local_ip);
  ESP_LOGI(TAG, "got ip:" IPSTR ", gw: " IPSTR, IP2STR(&local_ip.ip),
           IP2STR(&local_ip.gw));
  ping_config.target_addr.u_addr.ip4.addr = ip4_addr_get_u32(&local_ip.gw);
  ping_config.target_addr.type = ESP_IPADDR_TYPE_V4;

  esp_ping_callbacks_t cbs = {0};
  esp_ping_new_session(&ping_config, &cbs, &ping_handle);
  esp_ping_start(ping_handle);

  return ESP_OK;
}

void app_main(void) {
  ESP_ERROR_CHECK(nvs_flash_init());
  ESP_ERROR_CHECK(esp_netif_init());
  ESP_ERROR_CHECK(esp_event_loop_create_default());
  ESP_ERROR_CHECK(wifi_init_sta());

  vTaskDelay(pdMS_TO_TICKS(500));

  wifi_csi_init();
  wifi_ping_router_start();
}

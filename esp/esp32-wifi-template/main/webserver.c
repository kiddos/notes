#include "webserver.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "jsmn.h"
#include "json_generator.h"

#include "board_info.h"

static httpd_handle_t server = NULL;
static const char* TAG = "webserver";

static httpd_handle_t start_server(void);

static void disconnect_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data);

static jsmn_parser parser;
static void setup_json_parser() {
  jsmn_init(&parser);
}

httpd_handle_t* webserver_get() {
  return &server;
}

httpd_handle_t webserver_start(void) {
  ESP_ERROR_CHECK(esp_wifi_set_ps(WIFI_PS_NONE));

  if (server == NULL) {
    ESP_LOGI(TAG, "Starting webserver");
    server = start_server();
  }

  setup_json_parser();
  return server;
}

void webserver_handle_disconnect() {
    ESP_LOGI(TAG, "register event handler...");
    ESP_ERROR_CHECK(esp_event_handler_register(
        WIFI_EVENT, WIFI_EVENT_STA_DISCONNECTED, &disconnect_handler, &server));
}

static char info_buffer[1024];

static esp_err_t info_handler(httpd_req_t* req) {
  ESP_LOGI(TAG, "info handler");

  json_gen_str_t jstr;
  memset(info_buffer, 0, sizeof(info_buffer));

  esp_chip_info_t* chip_info = board_info_get_chip_info();
  unsigned major_rev = chip_info->revision / 100;
  unsigned minor_rev = chip_info->revision % 100;

  json_gen_str_start(&jstr, info_buffer, sizeof(info_buffer), NULL, NULL);
  json_gen_start_object(&jstr);
  json_gen_obj_set_int(&jstr, "major_rev", major_rev);
  json_gen_obj_set_int(&jstr, "minor_rev", minor_rev);
  json_gen_obj_set_int(&jstr, "cores", chip_info->cores);
  switch (chip_info->model) {
    case CHIP_ESP32:
      json_gen_obj_set_string(&jstr, "cores", "ESP32");
      break;
    case CHIP_ESP32S2:
      json_gen_obj_set_string(&jstr, "cores", "ESP32S2");
      break;
    case CHIP_ESP32S3:
      json_gen_obj_set_string(&jstr, "cores", "ESP32S3");
      break;
    case CHIP_ESP32C3:
      json_gen_obj_set_string(&jstr, "cores", "ESP32C3");
      break;
    case CHIP_ESP32C2:
      json_gen_obj_set_string(&jstr, "cores", "ESP32C2");
      break;
    case CHIP_ESP32C6:
      json_gen_obj_set_string(&jstr, "cores", "ESP32C6");
      break;
    case CHIP_ESP32H2:
      json_gen_obj_set_string(&jstr, "cores", "ESP32H2");
      break;
    case CHIP_POSIX_LINUX:
      json_gen_obj_set_string(&jstr, "cores", "POSIX LINUX");
      break;
    default:
      json_gen_obj_set_string(&jstr, "cores", "unknown");
      break;
  }
  json_gen_end_object(&jstr);
  json_gen_str_end(&jstr);

  httpd_resp_set_hdr(req, "Content-Type", "application/json");
  httpd_resp_set_hdr(req, "Connection", "close");

  httpd_resp_send(req, info_buffer, HTTPD_RESP_USE_STRLEN);
  return ESP_OK;
}

static const httpd_uri_t info = {
    .uri = "/api/info",
    .method = HTTP_GET,
    .handler = info_handler,
    .user_ctx = NULL,
};

static httpd_handle_t start_server(void) {
  httpd_handle_t server = NULL;
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
  config.lru_purge_enable = true;

  // Start the httpd server
  ESP_LOGI(TAG, "Starting server on port: '%d'", config.server_port);
  if (httpd_start(&server, &config) == ESP_OK) {
    ESP_LOGI(TAG, "Registering URI handlers");

    httpd_register_uri_handler(server, &info);
    // tODO

    return server;
  }

  ESP_LOGI(TAG, "Error starting server!");
  return NULL;
}

static void disconnect_handler(void* arg, esp_event_base_t event_base,
                               int32_t event_id, void* event_data) {
  httpd_handle_t* server = (httpd_handle_t*)arg;
  if (*server) {
    ESP_LOGI(TAG, "Stopping webserver");
    if (httpd_stop(*server) == ESP_OK) {
      *server = NULL;
    } else {
      ESP_LOGE(TAG, "Failed to stop http server");
    }
  }
}

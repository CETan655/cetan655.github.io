#ifndef ELS_OTA_APP_UPDATE_H
#define ELS_OTA_APP_UPDATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include <cJSON.h>
#include <driver/gpio.h>
#include <esp_system.h>
#include <esp_event.h>
#include <esp_log.h>
#include <esp_ota_ops.h>
#include <esp_http_client.h>
#include <esp_https_ota.h>

#include <nvs_flash.h>
#include <esp_wifi.h>

typedef struct  {
    const char *update_json_url;
    const int *interval_ticks;
} els_ota_app_update_config_t;

void els_ota_app_update(void *pvParameter);
void get_sha256_of_partitions(void);
void nvs_init();
void wifi_init(const char *wifi_ssid, const char *wifi_pass);

#ifdef __cplusplus
}
#endif

#endif

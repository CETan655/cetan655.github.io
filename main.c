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

#include <els_ota_app_update.h>

#define WIFI_SSID           "MARS"
#define WIFI_PASS           "elsoft@098!"
#define UPDATE_JSON_URL     "https://elsoftsys.github.io/mfkhoo/firmware.json"
#define INTERVAL_TICKS      30000

void app_main() {
    printf("TestingApp_PlatformIO_ArduinoAsComponent starting...\n");

    // get sha256 digest for partitions
    get_sha256_of_partitions();

    // connect to the wifi network
    nvs_init();
    wifi_init(WIFI_SSID, WIFI_PASS);
    
    els_ota_app_update_config_t ota_app_update_config = {
        .update_json_url = UPDATE_JSON_URL,
        .interval_ticks = (int *)INTERVAL_TICKS,
    };
    // start the els ota app update
    xTaskCreate(&els_ota_app_update, "els_ota_app_update", 8192, &ota_app_update_config, 5, NULL);
    
    while(true)
    {
        printf("%ld\n", (long int)xTaskGetTickCount());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
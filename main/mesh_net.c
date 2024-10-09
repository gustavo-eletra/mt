#include <esp_log.h>
#include "mesh_net.h"

//MAC address for mesh
static uint8_t MESH_ID[6] = {0x77, 0x77, 0x77, 0x77, 0x77, 0x77};

//Mesh Variables
static bool is_mesh_connected = false;
static mesh_addr_t mesh_parent_addr;
static int mesh_layer = -1;
static esp_netif_t *netif_sta = NULL;

//Task handles that can be deleted
TaskHandle_t net_receive_handle;
TaskHandle_t net_receive_handle;

void net_send_task(void *args)
{

}

void net_receive_task(void *args)
{

}

void mesh_send_task(void *args)
{

}

void mesh_receive_task(void *args)
{

}

void check_mesh_health_task(void *args)
{

}

//TODO: Better error handling
void wifi_init()
{
    esp_err_t ret = nvs_flash_init();

    if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(esp_netif_create_default_wifi_mesh_netifs(&netif_sta, NULL));

    wifi_init_config_t cfg_wifi = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg_wifi));
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, ESP_EVENT_ANY_ID, &ip_event_handler, NULL));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_FLASH));

    ESP_ERROR_CHECK(esp_wifi_start());
}

void wifi_event_handler(void *args, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    switch (event_id)
    {
    case WIFI_EVENT_STA_CONNECTED:
        ESP_LOGI(NET_TAG, "WIFI CONNECTED");
        break;

    case WIFI_EVENT_STA_DISCONNECTED:
        ESP_LOGI(NET_TAG, "WIFI DISCONNECTED");
        break;

    default:
        break;
    }
}

void ip_event_handler(void *args, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    ip_event_got_ip_t *event = (ip_event_got_ip_t *) event_data;
    ESP_LOGI(NET_TAG, "<IP_EVENT_STA_GOT_IP>IP:" IPSTR, IP2STR(&event->ip_info.ip));
}


void mesh_init()
{

}

//TODO: Better error handling
void mesh_event_handler(void *args, esp_event_base_t event_base, int32_t event_id, void *event_data)
{

}
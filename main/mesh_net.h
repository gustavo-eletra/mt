#pragma once

#include <string.h>
#include <inttypes.h>

#include <esp_event.h>
#include <nvs_flash.h>
#include <esp_wifi.h>
#include <esp_mac.h>
#include <esp_mesh.h>
#include <esp_mesh_internal.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//TCP/IP
#include <lwip/sockets.h>
#include <lwip/sys.h>

//Defines for network SSID and password
#define NET_SSID "ELHP"
#define NET_PASSWORD = "eletra2023"

//Defines for mesh SSID and password
#define MESH_SSID "meterfarm"
#define MESH_PASSWORD "meterfarm"

#define COMMS_BUFF 512

#define NET_TAG "NET"
#define MESH_TAG "MESH"

void net_send_task(void *args);
void net_receive_task(void *args);

void mesh_send_task(void *args);
void mesh_receive_task(void *args);

void check_mesh_health_task(void *args);

void wifi_init();
void wifi_event_handler(void *args, esp_event_base_t event_base, int32_t event_id, void *event_data);
void ip_event_handler(void *args, esp_event_base_t event_base, int32_t event_id, void *event_data);

void mesh_init();
void mesh_event_handler(void *args, esp_event_base_t event_base, int32_t event_id, void *event_data);
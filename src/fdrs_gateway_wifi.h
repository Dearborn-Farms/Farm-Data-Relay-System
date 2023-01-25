
#ifdef USE_WIFI
#include <WiFiUdp.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#include <esp_wifi.h>
#endif
// select WiFi SSID configuration
#if defined(WIFI_SSID)
#define FDRS_WIFI_SSID WIFI_SSID
#elif defined (GLOBAL_SSID)
#define FDRS_WIFI_SSID GLOBAL_SSID
#else 
// ASSERT("NO WiFi SSID defined! Please define in fdrs_globals.h (recommended) or in fdrs_sensor_config.h");
#endif //WIFI_SSID

// select WiFi password 
#if defined(WIFI_PASS)
#define FDRS_WIFI_PASS WIFI_PASS
#elif defined (GLOBAL_PASS)
#define FDRS_WIFI_PASS GLOBAL_PASS
#else 
// ASSERT("NO WiFi password defined! Please define in fdrs_globals.h (recommended) or in fdrs_sensor_config.h");
#endif //WIFI_PASS
#endif // USE_WIFI
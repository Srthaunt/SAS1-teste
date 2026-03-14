#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
// João Moreno
// definir pinos
#define RED 23
#define Green 19
void app_main() {
// varáeis de estado 
  gpio_set_direction(RED, GPIO_MODE_OUTPUT);
  gpio_set_direction(Green, GPIO_MODE_OUTPUT);
int estadoatual = 0;
int vezes =  5;
  switch (estadoatual) {
  // acionamento do led de sinalização vermelha ou pare
  case 0:
  printf("pare\n");
  gpio_set_direction (RED,1);
  gpio_set_direction (Green,0);
  vTaskDelay(5000 / portTICK_PERIOD_MS);
    estadoatual = 0;
    break; 
  // acionamento do led de sinalização verde ou continue
    case 1:
    printf("avance\n");
    gpio_set_direction (RED,0);
    gpio_set_direction (Green,1);
    vTaskDelay(5000 / portTICK_PERIOD_MS);
      estadoatual = 1;
    break;
// acionamento do led de sinalização vermelha em estado de cuidado
        case 3:
        printf("cuidado\n");
        for ( int i = 0; i < vezes; i++){
        gpio_set_direction (RED,1);
        gpio_set_direction (Green,0);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_set_direction (RED,0);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        estadoatual = 1;
          break;
    }
  }
}
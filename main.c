#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Pinos
#define VERMELHO 23

#define VERDE    19

//VARIÁVEL DE ESTADO 

int estado_atual = 0;
//0=Vermelho
//1=Verde


void inicializar_pinos() {
    gpio_reset_pin(VERMELHO);
    gpio_set_direction(VERMELHO, GPIO_MODE_OUTPUT);

    gpio_reset_pin(VERDE);
    gpio_set_direction(VERDE, GPIO_MODE_OUTPUT);
}

void app_main() {
    printf("Semáforo pedestre\n");
    inicializar_pinos();

    while (true) {
        
        switch(estado_atual) {
            case 0: // VERMELHO
                printf("Pare!\n");
                gpio_set_level(VERMELHO, 1);
                 gpio_set_level(VERDE, 0);
                vTaskDelay(3000 / portTICK_PERIOD_MS);
                estado_atual = 1; // Próximo passo: Verde
                break;

            case 1: // VERDE
                printf("Siga!\n");
                gpio_set_level(VERMELHO, 0);
                gpio_set_level(VERDE, 1);
                vTaskDelay(3000 / portTICK_PERIOD_MS);
                estado_atual = 2; // Próximo passo: Amarelo
                break;

            case 2: // vermelho piscante
                printf("Atenção!\n");
                gpio_set_level(VERDE, 0);
                gpio_set_level(VERMELHO, 1);
                vTaskDelay(100 / portTICK_PERIOD_MS);
                gpio_set_level(VERMELHO, 0);
                vTaskDelay(100 / portTICK_PERIOD_MS);
                gpio_set_level(VERMELHO, 1);
                vTaskDelay(100 / portTICK_PERIOD_MS);
                gpio_set_level(VERMELHO, 0);
                vTaskDelay(100 / portTICK_PERIOD_MS);
                gpio_set_level(VERMELHO, 1);
                vTaskDelay(100 / portTICK_PERIOD_MS);
                gpio_set_level(VERMELHO, 0);
                vTaskDelay(100 / portTICK_PERIOD_MS);
                 estado_atual = 0;
                break;
        }
    }
}

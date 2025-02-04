/* 
*********************************************************************
Naylane do Nascimento Ribeiro
EmbarcaTech - Tarefa 1, unidade 4, capítulo 5 (Clock e Interruptores)
*********************************************************************
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_PIN 13
#define BLUE_PIN 12
#define GREEN_PIN 11

// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    printf("Sinal mudou\n");

    if (gpio_get(RED_PIN)) {
        gpio_put(RED_PIN, 0);
        gpio_put(BLUE_PIN, 1);
    } else if (gpio_get(BLUE_PIN)) {
        gpio_put(BLUE_PIN, 0);
        gpio_put(GREEN_PIN, 1);
    } else if (gpio_get(GREEN_PIN)) {
        gpio_put(GREEN_PIN, 0);
        gpio_put(RED_PIN, 1);
    }

    return true;
}

int main() {
    stdio_init_all();

    gpio_init(RED_PIN);
    gpio_set_dir(RED_PIN, true);
    gpio_put(RED_PIN, 1);

    gpio_init(BLUE_PIN);
    gpio_set_dir(BLUE_PIN, true);
    gpio_put(BLUE_PIN, 0);

    gpio_init(GREEN_PIN);
    gpio_set_dir(GREEN_PIN, true);
    gpio_put(GREEN_PIN, 0);

    // Etrutura que armazena informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal.
    while (true) {
        sleep_ms(1000); // Pausa de 1 segundo.
        printf("+ 1 segundo se passou\n");
    }
    return 0;
}

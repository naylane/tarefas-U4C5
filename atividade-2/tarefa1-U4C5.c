#include "pico/stdlib.h"
#include "pico/time.h" 

#define RED_PIN 13
#define BLUE_PIN 12
#define GREEN_PIN 11
#define BUTTON_PIN 5

static volatile uint32_t last_press_time = 0; // Timestamp do último pressionamento válido
static volatile bool sys_free = true;         // váriavel que informa se a sequência foi finalizada


/**
 * @brief Função de callback do temporizador para transições de estado
 * 
 * @param id ID do alarme.
 * @param user_data Número da sequência atual.
 * @return retorna 0.
 */
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    uint8_t sequence = (uint8_t)user_data;

    switch (sequence) {
        case 1:
            gpio_put(BLUE_PIN, 0);
            add_alarm_in_ms(3000, turn_off_callback, (void*)2, false);
            break;
        case 2:
            gpio_put(RED_PIN, 0);
            add_alarm_in_ms(3000, turn_off_callback, (void*)3, false);
            break;
        case 3:
            gpio_put(GREEN_PIN, 0);
            sys_free = true;
            break;
    }

    return 0;
}


/**
 * @brief Rotina de Serviço de Interrupção (ISR) do botão. Todos os LEDs são acessos se a sequência estiver finalizada.
 * 
 * @param gpio GPIO que causou interrupção.
 * @param events evento que causou interrupção.
 */
void btn_interrupt(uint gpio, uint32_t events) {
    uint32_t now = to_ms_since_boot(get_absolute_time());
    
    // Verificação de debounce e estado ocupado
    if ((now - last_press_time) > 250 && sys_free) {
        sys_free = false;  // Bloqueia sistema durante operação
        
        // Ativa todos os LEDs
        gpio_put(RED_PIN, 1);
        gpio_put(GREEN_PIN, 1);
        gpio_put(BLUE_PIN, 1);        
        
        // Agenda um alarme para desligar os LEDs após 3 segundos. A primeira sequência é então acionada.
        add_alarm_in_ms(3000, turn_off_callback, 1, false);
        
        last_press_time = now;  // Atualiza timestamp
    }
}


/**
 * @brief Função principal.
 */
int main() {
    stdio_init_all();

    // Configuração dos LEDs como saída digital.
    gpio_init(GREEN_PIN);
    gpio_set_dir(GREEN_PIN, GPIO_OUT);
    gpio_put(GREEN_PIN, 0);

    gpio_init(RED_PIN);
    gpio_set_dir(RED_PIN, GPIO_OUT);
    gpio_put(RED_PIN, 0);

    gpio_init(BLUE_PIN);
    gpio_set_dir(BLUE_PIN, GPIO_OUT);
    gpio_put(BLUE_PIN, 0);

    // Configuração do botão como entrada digital.
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); // botão não pressionado = nível alto

    // Configuração de interrupção
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &btn_interrupt);

    while (true) {
        sleep_ms(50);
    }

    return 0;
}

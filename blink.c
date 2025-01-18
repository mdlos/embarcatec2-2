#include <stdio.h>
#include <string.h>  // Necessário para strcmp
#include "pico/stdlib.h"
#include "pico/bootrom.h" // Para a função reset_usb_boot

// Definição dos pinos
#define BUTTON_PIN 1
#define LED_G_PIN 11
#define LED_B_PIN 12
#define LED_R_PIN 13
#define BUZZER_PIN 21

// Estado do botão
bool button_pressed = false;

// Funções auxiliares
void turn_off_all_leds() {
    gpio_put(LED_R_PIN, false);
    gpio_put(LED_G_PIN, false);
    gpio_put(LED_B_PIN, false);
}

void execute_command(const char *command) {
    if (strcmp(command, "GREEN") == 0) {
        turn_off_all_leds();
        gpio_put(LED_G_PIN, true);
        printf("LED verde ligado\n");
    } else if (strcmp(command, "BLUE") == 0) {
        turn_off_all_leds();
        gpio_put(LED_B_PIN, true);
        printf("LED azul ligado\n");
    } else if (strcmp(command, "RED") == 0) {
        turn_off_all_leds();
        gpio_put(LED_R_PIN, true);
        printf("LED vermelho ligado\n");
    } else if (strcmp(command, "WHITE") == 0) {
        gpio_put(LED_R_PIN, true);   // Acende o LED vermelho
        gpio_put(LED_G_PIN, true);   // Acende o LED verde
        gpio_put(LED_B_PIN, true);   // Acende o LED azul
        printf("Todos os LEDs ligados (branco)\n");
    } else if (strcmp(command, "OFF") == 0) {
        turn_off_all_leds();
        printf("Todos os LEDs desligados\n");
    } else if (strcmp(command, "BUZZER") == 0) {
        gpio_put(BUZZER_PIN, true);
        sleep_ms(500); // Buzzer ativo por 500ms
        gpio_put(BUZZER_PIN, false);
        printf("Buzzer ativado\n");
    } else if (strcmp(command, "REBOOT") == 0) {
        // Reboot do RP2040 (habilita o modo de gravação via software)
        printf("Reiniciando...\n");
        reset_usb_boot(0, 0);  // Inicia o reboot do sistema e coloca o RP2040 no modo de gravação
    } else {
        printf("Comando inválido: %s\n", command);
    }
}

void handle_button_press() {
    if (!button_pressed && gpio_get(BUTTON_PIN)) {
        button_pressed = true; // Marca o botão como pressionado
        printf("Botão pressionado!\n");
        execute_command("BUZZER");
        sleep_ms(300); // Debounce
    } else if (button_pressed && !gpio_get(BUTTON_PIN)) {
        button_pressed = false; // Reseta o estado do botão
    }
}

int main() {
    // Inicialização dos pinos
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_down(BUTTON_PIN);

    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);

    gpio_init(LED_G_PIN);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);

    gpio_init(LED_B_PIN);
    gpio_set_dir(LED_B_PIN, GPIO_OUT);

    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    // Inicialização da comunicação serial
    stdio_init_all();
    printf("Sistema inicializado. Aguarde comandos...\n");

    char command_buffer[32];
    int buffer_index = 0;

    while (true) {
        handle_button_press(); // Verifica o estado do botão

        // Verifica se há caracteres disponíveis no buffer
        int c = getchar_timeout_us(0);
        if (c != PICO_ERROR_TIMEOUT) {
            if (c == '\n' || c == '\r') {
                // Final do comando
                command_buffer[buffer_index] = '\0';
                printf("Comando recebido: %s\n", command_buffer);
                execute_command(command_buffer);
                buffer_index = 0; // Reinicia o buffer
            } else if (buffer_index < sizeof(command_buffer) - 1) {
                // Adiciona o caractere ao buffer
                command_buffer[buffer_index++] = (char)c;
            }
        }
    }
    return 0;
}

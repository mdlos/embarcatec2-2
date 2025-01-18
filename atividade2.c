#include "pico/stdlib.h"
#include <string.h>

#define LED_VERMELHO_PIN 13
#define LED_AZUL_PIN 12
#define LED_VERDE_PIN 11

int main() {
    // Inicializa o SDK e configura os pinos GPIO
    stdio_init_all(); // Inicializa a comunicação serial via USB

    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);

    gpio_init(LED_AZUL_PIN);
    gpio_set_dir(LED_AZUL_PIN, GPIO_OUT);

    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);

    char comando[10]; // Array para armazenar a entrada do usuário

    while (true) {
        // Solicita que o usuário digite o comando
        printf("Digite um comando (red, green, blue): ");
        
        // Lê a string do terminal serial
        scanf("%s", comando); // Lê a palavra digitada

        // Exibe o comando digitado no terminal
        printf("Comando digitado: %s\n", comando);

        // Verifica o comando e acende o LED correspondente
        if (strcmp(comando, "red") == 0) {
            gpio_put(LED_VERMELHO_PIN, 1); // Liga o LED vermelho
            gpio_put(LED_AZUL_PIN, 0);     // Desliga os outros LEDs
            gpio_put(LED_VERDE_PIN, 0);
        } else if (strcmp(comando, "green") == 0) {
            gpio_put(LED_AZUL_PIN, 0);     // Desliga o LED azul
            gpio_put(LED_VERMELHO_PIN, 0); // Desliga o LED vermelho
            gpio_put(LED_VERDE_PIN, 1);    // Liga o LED verde
        } else if (strcmp(comando, "blue") == 0) {
            gpio_put(LED_AZUL_PIN, 1);     // Liga o LED azul
            gpio_put(LED_VERMELHO_PIN, 0); // Desliga os outros LEDs
            gpio_put(LED_VERDE_PIN, 0);
        } else {
            printf("Comando inválido! Tente 'red', 'green' ou 'blue'.\n");
        }
    }

    return 0;
}

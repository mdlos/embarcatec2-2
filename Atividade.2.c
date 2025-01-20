#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>

#define LED_VERMELHO_PIN 13
#define LED_AZUL_PIN 12
#define LED_VERDE_PIN 11
#define BUZZER_PIN 10 // Define o pino do buzzer

void bip_buzzer(uint frequency, uint duration_ms);
void tocar_happy_birthday();

int main() {
    // Inicializa o SDK e configura os pinos GPIO
    stdio_init_all(); // Inicializa a comunicação serial via USB

    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);

    gpio_init(LED_AZUL_PIN);
    gpio_set_dir(LED_AZUL_PIN, GPIO_OUT);

    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);

    gpio_init(BUZZER_PIN); // Inicializa o pino do buzzer
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Configura como saída

    char comando[10]; // Array para armazenar a entrada do usuário

    while (true) {
        // Solicita que o usuário digite o comando
        printf("Digite um comando: \n - red \n - green\n - blue\n - white\n - leds_off\n - bip\n - pink\n - ciano\n - birthday\n");
        
        // Lê a string do terminal serial
        scanf("%s", comando); // Lê a palavra digitada

        // Exibe o comando digitado no terminal
        printf("Comando digitado: %s\n", comando);

        // Verifica o comando e acende o LED correspondente ou liga o buzzer
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
        } else if (strcmp(comando, "bip") == 0) {
            // Emite um som de bip no buzzer
            bip_buzzer(1000, 500); // Frequência de 1000 Hz por 500 ms
        } else if (strcmp(comando, "white") == 0) {
            gpio_put(LED_VERMELHO_PIN, 1); // Liga o LED vermelho
            gpio_put(LED_AZUL_PIN, 1);     // Liga o LED azul
            gpio_put(LED_VERDE_PIN, 1);   // Liga o LED verde
        } else if (strcmp(comando, "leds_off") == 0) {
            gpio_put(LED_VERMELHO_PIN, 0); // Liga o LED vermelho
            gpio_put(LED_AZUL_PIN, 0);     // Liga o LED azul
            gpio_put(LED_VERDE_PIN, 0);   // Liga o LED verde
        } else if (strcmp(comando, "pink") == 0) {
            gpio_put(LED_VERMELHO_PIN, 1); // Liga o LED vermelho
            gpio_put(LED_AZUL_PIN, 1);     // Liga o LED azul
            gpio_put(LED_VERDE_PIN, 0);   // Liga o LED verde
        } else if (strcmp(comando, "ciano") == 0) {
            gpio_put(LED_VERMELHO_PIN, 0); // Liga o LED vermelho
            gpio_put(LED_AZUL_PIN, 1);     // Liga o LED azul
            gpio_put(LED_VERDE_PIN, 1);   // Liga o LED verde
        } else if (strcmp(comando, "birthday") == 0) {
            tocar_happy_birthday();
        }
         else {
            printf("Comando inválido! \n");
        }
    }

    return 0;
}

// Função para gerar um bip no buzzer
void bip_buzzer(uint frequency, uint duration_ms) {
    uint delay_us = 1000000 / (2 * frequency); // Calcula o atraso entre pulsos
    uint cycles = (frequency * duration_ms) / 1000; // Calcula o número de ciclos necessários

    for (uint i = 0; i < cycles; i++) {
        gpio_put(BUZZER_PIN, 1); // Liga o buzzer
        sleep_us(delay_us);      // Aguarda metade do período
        gpio_put(BUZZER_PIN, 0); // Desliga o buzzer
        sleep_us(delay_us);      // Aguarda metade do período
    }
}

// Função para tocar "Happy Birthday to You" no buzzer
void tocar_happy_birthday() {
    // Primeira linha: "Happy Birthday to You"
    bip_buzzer(264, 500); // Dó
    sleep_ms(250);

    bip_buzzer(264, 500); // Dó
    sleep_ms(250);

    bip_buzzer(297, 1000); // Ré
    sleep_ms(500);

    bip_buzzer(264, 1000); // Dó
    sleep_ms(500);

    bip_buzzer(352, 1000); // Fá
    sleep_ms(500);

    bip_buzzer(330, 2000); // Mi
    sleep_ms(1000);

    // Segunda linha: "Happy Birthday to You"
    bip_buzzer(264, 500); // Dó
    sleep_ms(250);

    bip_buzzer(264, 500); // Dó
    sleep_ms(250);

    bip_buzzer(297, 1000); // Ré
    sleep_ms(500);

    bip_buzzer(264, 1000); // Dó
    sleep_ms(500);

    bip_buzzer(396, 1000); // Sol
    sleep_ms(500);

    bip_buzzer(352, 2000); // Fá
    sleep_ms(1000);
}

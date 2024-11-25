// Pico SDK libraries
#include "pico/stdlib.h"
#include "pico/time.h"

// Standard libraries
#include <stdio.h>
#include <stdbool.h>

#define LED_PIN 6
#define BUTTON_PIN 20
#define BUTTON1_PIN 21

void init();

void handler(uint gpio, uint32_t events);
uint32_t millis();

int number = 0;

uint32_t lastIrgTime = 0;

int main()
{
    // Initialize all standard I/O
    stdio_init_all();
    // Wait for serial monitor to reconnect
    sleep_ms(2000);
    printf("Starting...\n");

    init();

    // Enable interrupts for button pin
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_RISE, true, &handler);
    gpio_set_irq_enabled_with_callback(BUTTON1_PIN, GPIO_IRQ_EDGE_RISE, true, &handler);
 

    // Infinite loop
    while (1)
    {
        printf("\rRun...");
        printf("%d\n", number);
        sleep_ms(1000);
    }
    return 0;
}

void handler(uint gpio, uint32_t events)
{
    if ((millis() - lastIrgTime) >= 200) {
        gpio_put(LED_PIN, !gpio_get(LED_PIN));
        lastIrgTime = millis();
        if(gpio == BUTTON_PIN){
           number++; 
        }else if(gpio == BUTTON1_PIN){
            number--;
        }
    }
}

uint32_t millis() {
    return to_ms_since_boot(get_absolute_time());
}



void init(){
    // Initialize GPIO pins
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_pull_up(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);

    gpio_init(BUTTON1_PIN);
    gpio_pull_up(BUTTON1_PIN);
    gpio_set_dir(BUTTON1_PIN, GPIO_IN);
}
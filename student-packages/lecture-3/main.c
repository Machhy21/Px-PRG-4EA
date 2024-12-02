// Pico SDK libraries
#include "pico/stdlib.h"

// Standard libraries
#include <stdio.h>

//PWM and GPIO libraries?
#include "hardware/pwm.h"
#include "hardware/gpio.h"

//definition of constants
#define LED_PIN 7
#define LEVEL 1000

//declaration of functions
void init();
void led_wave();

int main()
{
    // Initialize all standard I/O
    stdio_init_all();
    init();
    // Wait for serial monitor to reconnect
    sleep_ms(2000);
    printf("Starting...\n");

    led_wave();

    return 0;
}

//definition of functions
void init(){
    uint slice_num = pwm_gpio_to_slice_num(LED_PIN);
    //uint channel = pwm_gpio_to_channel(LED_PIN);

    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    pwm_set_gpio_level(LED_PIN, LEVEL);

    pwm_config_set_clkdiv(&config, 125);
    pwm_config_set_wrap(&config, 1000);

}

void led_wave(){
    int level;
    while(1){
        for(i = 0; i < 1000; i++){
            level = i;
            pwm_set_gpio_level(LED_PIN, level);
        }
        for(i = 0; i > 1000; i++){
            level = i;
            pwm_set_gpio_level(LED_PIN, level);
        }
    }
}
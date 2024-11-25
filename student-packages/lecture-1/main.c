// Pico SDK libraries
#include "pico/stdlib.h"

#define LED_PIN 6
#define BLINK_DELAY_MS_SHORT 100
#define BLINK_DELAY_MS_LONG 300

//function
void dot();
//void 

int main()
{
    // Initialize GPIO pins
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Infinite loop
    while (1)
    {
        for(int i = 0; i < 3; i++){
            // Turn on the LED
            gpio_put(LED_PIN, 1);
            sleep_ms(BLINK_DELAY_MS_SHORT);

            // Turn off the LED
            gpio_put(LED_PIN, 0);
            sleep_ms(BLINK_DELAY_MS_SHORT);
        }

        for(int i = 0; i < 3; i++){
            // Turn on the LED
            gpio_put(LED_PIN, 1);
            sleep_ms(BLINK_DELAY_MS_LONG);

            // Turn off the LED
            gpio_put(LED_PIN, 0);
            sleep_ms(BLINK_DELAY_MS_LONG);
        }

        for(int i = 0; i < 3; i++){
            // Turn on the LED
            gpio_put(LED_PIN, 1);
            sleep_ms(BLINK_DELAY_MS_SHORT);

            // Turn off the LED
            gpio_put(LED_PIN, 0);
            sleep_ms(BLINK_DELAY_MS_SHORT);
        }
        sleep_ms(BLINK_DELAY_MS_LONG);
        
    }
    return 0;
}

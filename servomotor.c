#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // GPIO para o servomotor

// Definições do PWM para o servo
#define PWM_FREQUENCY 50         // 50Hz (período de 20ms)
#define CLOCK_DIVIDER 64.0        // ajuste do clock do PWM
#define PWM_WRAP 3906             // valor máximo do contador para 50Hz
#define SERVO_MIN 500             // 0° - Pulso de 500µs
#define SERVO_MID 1470            // 90° - Pulso de 1470µs
#define SERVO_MAX 2400            // 180° - Pulso de 2400µs
#define STEP 5                    // incremento de 5µs para movimentação suave
#define DELAY 10                   // delay de 10ms entre os passos

//função para configurar o PWM
void setup_pwm() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, CLOCK_DIVIDER);
    pwm_config_set_wrap(&config, PWM_WRAP);

    pwm_init(slice_num, &config, true);
}

// função para definir o ângulo do servomotor
void set_servo_angle(uint16_t pulse_width) {
    pwm_set_gpio_level(SERVO_PIN, pulse_width);
}

// movimentação suave do servo entre 0° e 180°
void move_smoothly(uint16_t start, uint16_t end) {
    int step = (start < end) ? STEP : -STEP;
    for (uint16_t pos = start; pos != end; pos += step) {
        set_servo_angle(pos);
        sleep_ms(DELAY);
    }
}

int main() {
    stdio_init_all();
    setup_pwm();

    while (true) {
        printf("Movendo para 0°\n");
        set_servo_angle(SERVO_MIN);
        sleep_ms(5000);

        printf("Movendo para 90°\n");
        set_servo_angle(SERVO_MID);
        sleep_ms(5000);

        printf("Movendo para 180°\n");
        set_servo_angle(SERVO_MAX);
        sleep_ms(5000);

        printf("Movimentação suave de 180° a 0° e vice-versa\n");
        move_smoothly(SERVO_MAX, SERVO_MIN);
        sleep_ms(1000);
        move_smoothly(SERVO_MIN, SERVO_MAX);
        sleep_ms(1000);
    }
}

#ifndef PWM_H_
#define PWM_H_

void config_pwm_timer(void);
void start_pwm(uint8_t duty_cycle);
void stop_pwm(void);
 void config_pwm_gpio(void);

#endif

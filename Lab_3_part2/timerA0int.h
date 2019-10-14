#ifndef TIMERA0INT_H_
#define TIMERA0INT_H_

void config_interrupt_timer(void);
void start_interrupt(void);
void stop_interrupt(void);
void config_interrupt_gpio(void);
void TA0_0_IRQHandler (void);

#endif /* TIMERA0INT_H_ */

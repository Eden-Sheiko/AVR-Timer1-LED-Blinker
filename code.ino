// Define constants for Timer1 prescaler bits, CTC configuration, compare match interrupt, and compare value
#define TIMER_PRESCALER_BITS ((1 << CS12) | (0 << CS11) | (1 << CS10))
#define TIMER_CONFIGURE_CTC  (1 << WGM12)
#define TIMER_COMPARE_MATCH  (1 << OCIE1A)
#define VAL 15625 // (16,000,000 / 1024) / 1 = 15625

void setup() {
  // Set pin 13 (PB5) as an output
  DDRB |= (1 << DDB5);

  // Disable interrupts
  cli();

  // Clear Timer1 control registers
  TCCR1A = 0;
  TCCR1B = 0;

  // Set Timer1 counter value to 0
  TCNT1 = 0;

  // Set Timer1 prescaler to 1024
  TCCR1B |= TIMER_PRESCALER_BITS;

  // Configure Timer1 for CTC Mode where TOP = OCR1A
  TCCR1B |= TIMER_CONFIGURE_CTC;

  // Set the value for the output compare register
  OCR1A = VAL;

  // Enable Timer1 compare match interrupt
  TIMSK1 |= TIMER_COMPARE_MATCH;

  // Enable interrupts
  sei();
}

// Interrupt Service Routine (ISR) for Timer1 compare match interrupt
ISR(TIMER1_COMPA_vect) {
  // Toggle the LED state
  PORTB ^= (1 << PORTB5);
}

void loop() {
  // Nothing to do here since all timing and pin toggling is handled by the Timer1 compare match interrupt
}

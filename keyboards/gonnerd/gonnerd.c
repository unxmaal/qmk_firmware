#include "gonnerd.h"

void matrix_init_kb(void) {
	DDRB |= (1<<6);
	PORTB &= ~(1<<6);
	matrix_init_user();
}
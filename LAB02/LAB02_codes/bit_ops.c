#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    return (x >> n) & 1;  // Shift right n bits, mask with 1 to get the bit
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    if (v == 1) {
        *x |= (1U << n);   // Set nth bit to 1 using OR
    } else {
        *x &= ~(1U << n);  // Set nth bit to 0 using AND with NOT
    }
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31. */
void flip_bit(unsigned *x, unsigned n) {
    *x ^= (1U << n);      // Flip nth bit using XOR
}

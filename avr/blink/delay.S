#include "config.h"
    .global      delay
    .section    .text
delay:
        ldi      r26, 255
1:      call     loop
        dec      r26
        brne     1b
        ret

loop:
        ldi      r30, 255
1:      call     innerloop
        dec      r30
        brne     1b
        ret

innerloop:
        ldi      r31, 255
1:      dec      r31
        brne     1b
        ret

#include "delay.h"

void delay(uint32 milliseconds)
{
    uint64 cycles = 16000 * milliseconds;
    for (uint64 i = 0; i < cycles; i++)
        ;
}
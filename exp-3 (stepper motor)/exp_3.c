// HALF DRIVE

#include <reg51.h>

void Delay(void) {
    unsigned int x;
    for (x = 0; x < 1000; x++) {
        TMOD = 0x01;     // Timer 0 in Mode 1
        TH0 = 0xFC;      // Load high byte for ~1ms delay
        TL0 = 0x18;      // Load low byte
        TR0 = 1;         // Start Timer 0
        while (TF0 == 0); // Wait for overflow
        TR0 = 0;         // Stop Timer
        TF0 = 0;         // Clear overflow flag
    }
}

void main() {
    while (1) {
        P1 = 0x08;  // Step 1
        Delay();
        P1 = 0x0C;  // Step 2
        Delay();
        P1 = 0x04;  // Step 3
        Delay();
        P1 = 0x06;  // Step 4
        Delay();
        P1 = 0x02;  // Step 5
        Delay();
        P1 = 0x03;  // Step 6
        Delay();
        P1 = 0x01;  // Step 7
        Delay();
        P1 = 0x09;  // Step 8
        Delay();
    }
}

//===========================================================

// FULL DRIVE

#include <reg51.h>

void Delay(void) {
    unsigned int x;
    for (x = 0; x < 1000; x++) {
        TMOD = 0x01;     // Timer 0 in Mode 1
        TH0 = 0xFC;      // Load high byte for ~1ms delay
        TL0 = 0x18;      // Load low byte
        TR0 = 1;         // Start Timer 0
        while (TF0 == 0); // Wait for overflow
        TR0 = 0;         // Stop Timer
        TF0 = 0;         // Clear overflow flag
    }
}

void main() {
    while (1) {
        P1 = 0x0C;  // Coil A+B
        Delay();
        P1 = 0x06;  // Coil B+C
        Delay();
        P1 = 0x03;  // Coil C+D
        Delay();
        P1 = 0x09;  // Coil D+A
        Delay();
    }
}

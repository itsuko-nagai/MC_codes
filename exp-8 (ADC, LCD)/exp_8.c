#include <p18f4520.h>

#pragma config OSC = HS
#pragma config PWRT = OFF
#pragma config WDT = OFF
#pragma config DEBUG = OFF, LVP = OFF

void lcdcmd(unsigned char value);
void lcddata(unsigned char value);
void msdelay(unsigned int itime);

#define ldata PORTD
#define rs PORTCbits.RC3
#define rw PORTCbits.RC4
#define en PORTCbits.RC5

void main(void) {
    unsigned int i, d;
    unsigned char val, temp[3];

    TRISD = 0x00;
    PORTD = 0x00;
    TRISC = 0x00;
    PORTC = 0x00;

    ADCON0 = 0x01;             // Select AN0, ADC ON
    ADCON1 = 0x0E;             // AN0 analog, rest digital
    ADCON2 = 0b10001010;       // Right justified, Fosc/32, acquisition time 4TAD

    msdelay(15);
    lcdcmd(0x38);              // LCD 2 lines, 5x7 matrix
    msdelay(15);
    lcdcmd(0x0E);              // Display ON, cursor ON
    msdelay(15);
    lcdcmd(0x01);              // Clear display
    msdelay(15);
    lcdcmd(0x06);              // Increment cursor
    msdelay(15);

    while (1) {
        lcdcmd(0x80);          // Move cursor to beginning
        msdelay(20);

        ADCON0bits.GO = 1;     // Start conversion
        while (ADCON0bits.DONE == 1);  // Wait for completion

        temp[0] = (ADRESH & 0x0F);
        temp[1] = (ADRESL & 0xF0);
        temp[2] = (ADRESL & 0x0F);

        for (d = 0; d < 3; d++) {
            if (temp[d] < 10)
                temp[d] = temp[d] + 0x30;  // Convert to ASCII '0'–'9'
            else
                temp[d] = temp[d] + 0x37;  // Convert to ASCII 'A'–'F'

            lcddata(temp[d]);
            msdelay(15);
        }

        msdelay(10);
    }
}

void lcdcmd(unsigned char value) {
    ldata = value;
    rs = 0;
    rw = 0;
    en = 1;
    msdelay(1);
    en = 0;
}

void lcddata(unsigned char value) {
    ldata = value;
    rs = 1;
    rw = 0;
    en = 1;
    msdelay(1);
    en = 0;
}

void msdelay(unsigned int itime) {
    int i, j;
    for (i = 0; i < itime; i++)
        for (j = 0; j < 1235; j++);
}

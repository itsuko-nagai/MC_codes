#include <p18f4520.h>

#pragma config OSC = HS
#pragma config PWRT = OFF
#pragma config WDT = OFF
#pragma config DEBUG = OFF, LVP = OFF

unsigned char text1[] = {"SKNCOE"};
unsigned char text2[] = {"PUNE"};

void delay(unsigned int value);
void lcdcmd(unsigned char value);
void lcddata(unsigned char value);
void lcdinit(void);
void lcddisplay(int row, unsigned char *str);

#define ldata PORTD
#define rs PORTCbits.RC3
#define rw PORTCbits.RC4
#define en PORTCbits.RC5

void main() {
    TRISD = 0x00;       // PORTD as output
    TRISC = 0x00;       // PORTC as output
    ADCON1 = 0x0F;      // Configure all pins as digital

    lcdinit();
    lcddisplay(1, text1);
    lcddisplay(2, text2);

    while (1);          // Infinite loop
}

void lcddisplay(int row, unsigned char *str) {
    int k;

    if (row == 1)
        lcdcmd(0x80);   // Start of first line
    else
        lcdcmd(0xC0);   // Start of second line

    for (k = 0; k < 16; k++) {
        if (str[k] != 0)
            lcddata(str[k]);
        else
            break;
    }

    while (k < 16) {
        lcddata(' ');   // Fill remaining space with blanks
        k++;
    }
}

void delay(unsigned int value) {
    int i, j;
    for (i = 0; i <= value; i++)
        for (j = 0; j <= 50; j++);
}

void lcdcmd(unsigned char value) {
    ldata = value;
    rs = 0;
    rw = 0;
    en = 1;
    delay(1);
    en = 0;
}

void lcddata(unsigned char value) {
    ldata = value;
    rs = 1;
    rw = 0;
    en = 1;
    delay(1);
    en = 0;
}

void lcdinit(void) {
    lcdcmd(0x38);   // 2 lines, 5x7 matrix
    delay(1);
    lcdcmd(0x0E);   // Display ON, cursor ON
    delay(1);
    lcdcmd(0x01);   // Clear display
    delay(1);
    lcdcmd(0x06);   // Increment cursor
    delay(1);
}

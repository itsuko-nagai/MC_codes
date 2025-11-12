#include <P18F4520.h>

#pragma config OSC = HS    
#pragma config WDT = OFF   
#pragma config LVP = OFF    
#pragma config PBADEN = OFF   

void Transmit_String(unsigned char *string) {
    unsigned char i = 0;
    while (string[i] != '\0') {
        while (PIR1bits.TXIF == 0);  // Wait until transmit buffer is empty
        TXREG = string[i];           // Load character into transmit register
        i++;
    }
}

unsigned char MSG1[] = "UART COMMUNICATION \r\n";
unsigned char MSG2[] = "TRANSMITTING STRING \r\n";
unsigned char MSG3[] = "SEND 10 Characters \r\n";
unsigned char MSG4[] = "Received Data \r\n";

void main(void) {
    unsigned char j = 0;
    unsigned char RX_DATA[20];

    TRISCbits.TRISC7 = 1;   // RX pin as input
    TRISCbits.TRISC6 = 0;   // TX pin as output

    RCSTA = 0x90;           // Enable serial port and continuous receive
    TXSTA = 0x24;           // Enable transmitter, set BRGH
    BAUDCON = 0x00;         // Baud rate control
    SPBRG = 0x19;           // Baud rate low byte
    SPBRGH = 0x00;          // Baud rate high byte

    Transmit_String(MSG1);
    Transmit_String(MSG2);
    Transmit_String(MSG3);

    for (j = 0; j < 10; j++) {
        while (PIR1bits.RCIF == 0);  // Wait until data is received
        RX_DATA[j] = RCREG;          // Read received character
    }

    RX_DATA[10] = '\0';              // Null-terminate the string

    Transmit_String(MSG4);
    Transmit_String(RX_DATA);

    while (1);  // Infinite loop
}

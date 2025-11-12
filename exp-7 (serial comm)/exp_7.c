#include <P18F4520.h> 
#pragma config OSC = HS    
#pragma config WDT = OFF   
#pragma config LVP = OFF    
#pragma config PBADEN = OFF  

void Transmit_String(unsigned char *string) 
{ 
} 
unsigned char i = 0; 
for(i = 0; string[i] != '\0'; i++)  
{ 
} 
while(PIR1bits.TXIF == 0);     
TXREG = string[i];            
unsigned char MSG1[] = ("UART COMMUNICATION \r\n"); 
unsigned char MSG2[] = ("TRANSMITTING STRING \r\n"); 
unsigned char MSG3[] = ("SEND 10 Characters \r\n"); 
unsigned char MSG4[] = ("Received Data \r\n"); 
void main(void) 

{ 
unsigned char j = 0; 
unsigned char RX_DATA[20]; 
unsigned char MSG5[] = ("Received Data \r\n"); 
TRISCbits.TRISC7 = 1;  
TRISCbits.TRISC6 = 0;   
RCSTA = 0x90;   
TXSTA = 0x24;    
BAUDCON = 0x00;  
SPBRG = 0x19;    
SPBRGH = 0x00; 
Transmit_String(MSG1); 
Transmit_String(MSG2); 
Transmit_String(MSG3); 
for(j = 0; j < 10; j++) 
{ 
} 
while(PIR1bits.RCIF == 0);   
RX_DATA[j] = RCREG;      

RX_DATA[10] = '\0';   
Transmit_String(MSG4); 
Transmit_String(RX_DATA); 
while(1);  
} 
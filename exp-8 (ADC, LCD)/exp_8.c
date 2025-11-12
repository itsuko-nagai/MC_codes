#include<p18f4520.h>  
#pragma config OSC=HS  
#pragma config PWRT=OFF 
#pragma config WDT=OFF 
#pragma config DEBUG=OFF, LVP =OFF 
void lcdcmd(unsigned char value); 
void lcddata(unsigned char value); 
void msdelay(unsigned int itime); 
#define ldata PORTD 
#define rs PORTCbits.RC3 
#define rw PORTCbits.RC4 
#define en PORTCbits.RC5 
Void main(void) 
{ 
unsigned int I, d; 
unsigned char val, temp[3]; 
TRISD=0; 
PORTD=0; 
TRISC=0x00; 
PORTC=0; 
ADCON0=0X01; 
ADCON1=0X0E;  
ADCON2=0b10001010; 
msdelay(15); 
lcdcmd(0x38); 
msdelay(15); 
lcdcmd(0x0E); 
msdelay(15); 
lcdcmd(0x01); 
msdelay(15); 
lcdcmd(0x06); 
msdelay(15); 
while(1) 
{ 
lcdcmd(0x80); 
msdelay(20); 
ADCON0bits.GO=1; 
while(ADCON0bits.DONE==1); 
temp[0]=(ADRESH & 0x0f); 
temp[1]=(ADRESL & 0xf0); 
temp[2]=(ADRESL & 0x0f); 
for(d = 0; d < 3; d++) 
{ 
if (temp[d] < 10) 
temp[d] = temp[d] + 0x30;  
else 
temp[d] = temp[d] + 0x37; 
  
lcddata(temp[d]); 
msdelay(15); 
} 
msdelay(10); 
} 
} 
void lcdcmd(unsigned char value) 
{ 
ldata = value; 
rs = 0; 
rw = 0; 
en = 1; 
msdelay(1); 
en = 0; 
} 
void lcddata(unsigned char value) 
{ 
ldata = value; 
rs = 1; 
rw = 0; 
en = 1; 
msdelay(1); 
en = 0; 
} 
void msdelay(unsigned int itime) 

{ 
int i, j; 
for(i = 0; i < itime; i++) 
for(j = 0; j < 1235; j++); 
} 
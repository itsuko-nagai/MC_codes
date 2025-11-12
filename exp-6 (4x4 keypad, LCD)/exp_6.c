#include<p18f4520.h>
 #include"lcd.h"
 #pragma config OSC=HS
 #pragma config PWRT=OFF
 #pragma config WD=OFF
 #pragma config DEBUG=OFF, LVP=OFF
 void delay(unsigned int itime);
 #define R1 PORTBbits.RB0
 #define R2 PORTBbits.RB1
 #define R3 PORTBbits.RB2
 #define R4 PORTBbits.RB3
 #define C1 PORTBbits.RB4
 #define C2 PORTBbits.RB5
 #define C3 PORTBbits.RB6
 #define C4 PORTBbits.RB7
 unsigned char text1[]={"SKNCOE"};
 unsigned char text2[]={"KEY PRESSED:"};
 void main(void){
 TRISD=0x00;
 TRISC=0x00;
 ADCON1=0x0f;
 TRISBbits.TRISB0=1;
 TRISBbits.TRISB1=1;
 TRISBbits.TRISB2=1;
 1
TRISBbits.TRISB3=1;
 TRISBbits.TRISB4=0;
 TRISBbits.TRISB5=0;
 TRISBbits.TRISB6=0;
 TRISBbits.TRISB7=0;
 lcdinit();
 lcddisplay(1,text1);
 lcddisplay(2,text2);
 while(1) {
 C1=0;C2=C3=C4=1;
 if(R1==0){lcddat('F');}
 if(R2==0){lcddat('B');}
 if(R3==0){lcddat('7');}
 if(R4==0){lcddat('3');}
 C2=0;C1=C3=C4=1;
 if(R1==0){lcddat('E');}
 if(R2==0){lcddat('A');}
 if(R3==0){lcddat('6');}
 if(R4==0){lcddat('2');}
 C3=0;C1=C2=C4=1;
 if(R1==0){lcddat('D');}
 if(R2==0){lcddat('9');}
 if(R3==0){lcddat('5');}
 if(R4==0){lcddat('1');}
 C4=0;C1=C2=C3=1;
 if(R1==0){lcddat('C');}
 2
if(R2==0){lcddat('8');}
 if(R3==0){lcddat('4');}
 if(R4==0){lcddat('0');}
 }
 }
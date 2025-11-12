 #include<p18f4520.h>
 #pragma config OSC=HS
 #pragma config PWRT=OFF
 #pragma config WDT=OFF
 #pragma config DEBUG=OFF
 #pragma config LVP=OFF
 #define SW1 PORTDbits.RD0
 #define SW2 PORTDbits.RD1
 #define relay PORTDbits.RD3
 #define D0 PORTDbits.RD4
 #define D1 PORTDbits.RD5
 #define D2 PORTDbits.RD6
 #define D3 PORTDbits.RD7
 void left();
 void right();
 void delay(unsigned int);
 void main()
 {
 TRISD=0x03;
 PORTDbits.RD3=0;
 while(1)
 {
 if(SW1==0 && SW2==1)
 1
{
 relay=0;
 left();
 }
 if(SW1==1 && SW2==0)
 {
 relay=1;
 right();
 }
 }
 }
 void left()
 {
 relay=0;
 while(SW2==1)
 {
 D0=0;D1=0;D2=0;D3=1;
 delay(10);
 D0=0;D1=0;D2=1;D3=0;
 delay(10);
 D0=0;D1=1;D2=0;D3=0;
 delay(10);
 D0=1;D1=0;D2=0;D3=0;
 delay(10);
 }
 2
}
 void right()
 {
 relay=1;
 while(SW1==1)
 {
 D0=1;D1=0;D2=0;D3=0;
 delay(10);
 D0=0;D1=1;D2=0;D3=0;
 delay(10);
 D0=0;D1=0;D2=1;D3=0;
 delay(10);
 D0=0;D1=0;D2=0;D3=1;
 delay(10);
 }
 }
 void delay(unsigned int itime)
 {
 int i,j;
 for(i=0;i<itime;i++)
 for(j=0;j<1275;j++);
 }
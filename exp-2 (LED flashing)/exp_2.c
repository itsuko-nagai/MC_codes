// LED FLASHING

#include<reg51.h> 
void Delay(void); 
void main (void) 
{ 
    while(1) 
    { 
    P2 = 0x00; 
    Delay(); 
    P2 = 0xFF; 
    Delay(); 
    } 
} 
void Delay(void) 
{ 
int i; 
TMOD =0x01; 
for(i=0;i<1000;i++) 
    { 
    TL0=0x18; 
    TH0=0xFC; 
    TR0=1; 
    while(TF0==0); 
    TR0=0; 
    TF0=0; 
    } 
}

//===========================================================

// BCD

#include <reg51.h>

void Delay(void);

void main(void)
{
    unsigned char count = 0;
    unsigned char tens, ones;

    while (1)
    {
        tens = count / 10;
        ones = count % 10;

        P1 = ones;
        P2 = tens;

        Delay();

        count++;

        if (count == 100)
            count = 0;
    }
}

void Delay(void)
{
    int i, j;
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 1000; j++);
    }
}

//===========================================================

// HEX COUNTER

#include<reg51.h> 
void Delay(void); 
void main (void) 
{ 
unsigned char count=0x00; 
while(1) 
{ 
P2 = count; 
Delay(); 
count= count+1; 
} 
} 
void Delay(void) 
{ 
int i,j; 
for(i=0;i<100;i++) 
{ 
for(j=0;j<1000;j++) 
{ 
} 
} 
}

//===========================================================


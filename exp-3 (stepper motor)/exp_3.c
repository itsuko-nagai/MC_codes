// HALF DRIVE

#include<reg51.h> 
void Delay(void) 
{ 
unsigned int x; 
for (x=0; x<1000; x++) 
{ 
TMOD=0x01; 
TH0=0xFC; 
TL0=0x18; 
TR0=1; 
while (TF0==0); 
TR0=0; 
TF0=0; 
} 
} 
void main() 
{ 
while(1) 
{ 
P1=0x08; 
Delay(); 
P1=0x0C; 
Delay(); 
P1=0x04; 
Delay(); 
P1=0x06; 
Delay(); 
P1=0x02; 
Delay(); 
P1=0x03; Delay(); 
P1=0x01; 
P1=0x09; 
Delay(); 
} 
}

//===========================================================

// FULL DRIVE

#include<reg51.h> 
void Delay(void) 
{ 
unsigned int x; 
for (x=0; x<1000; x++) 
{ 
TMOD=0x01; 
TH0=0xFC; 
TL0=0x18; 
TR0=1; 
while (TF0==0); 
TR0=0; 
TF0=0; 
} 
} 
void main() 
{ 
while(1) 
{ 
P1=0x0C; 
Delay(); 
P1=0x06; 
Delay(); 
P1=0x03; 
Delay(); 
P1=0x09; 
Delay(); 
} 
}

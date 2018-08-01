#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTC
#include<mamalib/lcd.h>
#include<mamalib/keypad.h>

void main()
{
 DDRA=0b11100000;
 PORTA=0b00001111;//0b00011111 for calc()
 DDRB=0xff;
 DDRD=0xff;
 DDRC=0xff;
 lcd_init();
 lcd_command(0x80);
 lcd_string("enter the password");
 start:
 lcd_command(0xc0);
 lcd_string("                ");//16-spaces
 lcd_command(0xc0);
 int flag=0;

   unsigned char password[]={'\0'};
   unsigned char pass[]={"7398046334"};
   unsigned int x=0;
    for(int i=0;i<10;i++)
	{
	     x=keypad_calc();//....calling way
	    lcd_data(x);
	    //_delay_ms(4000);
		password[i]=x;
	//if(i==9)
		//break;
	}
	
	
	for(int i=0;i<10;i++)
	{
	  if(password[i]==pass[i])
	  flag=1;
	  else 
	 flag=0;
	}
	if(flag==1)
	{
	PORTB=0b10000000;////////////indication for unlock

	}
	else
	{
	lcd_command(0xc0);
	lcd_string("wrong password");////////wrong one
	_delay_ms(1000);
	goto start;
	}
	
	
 
}

#include<reg52.h>
sbit RW=P2^5;
sbit RS=P2^6;
sbit E=P2^7;
sbit LED=P3^2;
sbit KEY1=P2^0;
sbit KEY2=P2^1;
sbit KEY3=P2^2;
sbit KEY4=P2^3;
sbit KEY5=P2^4;
sbit buzzer=P1^0;
#define uchar unsigned char
#define uint unsigned int
#define beat 70
uchar a,t;
uchar K1='1',K2='2',K3='3',K4='4';
uint num[]= {0,6,7,8,9,10,11,12,13,14,15};
uint code tone[]= {0,63391,63511,63624,63731,63832,63928,64018,64103,64138,64259,64331,64398,64462,64522,64578,64632,64682};
uint code open[]= {0,6,3,6,8,6,10,6,12,26,10,6,12,6,15,6,17,6,10,12,10,0,0};
uint code close[]={0,4,12,2,10,2,2,4,5,4,12,2,10,2,2,4,5,4,12,2,10,2,2,4,5,4,10,8,0,0};
uint code danger[]= {0,6,8,6,4,6,8,6,4,6,8,6,4,6,8,6,4,6,8,6,4,6,0,0};
uint m,sign=0,reset=0;
int PWM_Low,Clock=50;
void delay(int x)
{
    int i,j;
    for(i=0; i<x; i++)
        for(j=0; j<110; j++);
}
void Timer0init()
{
    TMOD=0x01;
    ET0=1;
    TR0=1;
    TH0=tone[a]/256;
    TL0=tone[a]%256;
}
void Timer0()interrupt 1
{
	  PT0=1;
    TH0=tone[a]/256;
    TL0=tone[a]%256;
    buzzer=!buzzer;
}
void song()
{
    if(a)
    TR0=1;
    delay(t*beat);
    TR0=0;
}
void write_com(char com)
{
    E = 0;
    RW = 0;
    RS = 0;
    P0 = com;
    delay(1);
    E = 1;
    delay(5);
    E = 0;
}

void write_data(char dat)
{
    E = 0;
    RS = 1;
    RW = 0;
    P0 = dat;
    delay(1);
    E = 1;
    delay(5);
    E = 0;
}

int key_on()
{
    if(KEY1==0)
    {
        delay(15);
        if(KEY1==0)
        {
            return 1;
        }
        else
            return 0;
    }

    else if(KEY2==0)
    {
        delay(15);
        if(KEY2==0)
        {
            return 2;
        }
        else
            return 0;
    }
    else if(KEY3==0)
    {
        delay(15);
        if(KEY3==0)
        {
            return 3;
        }
        else
            return 0;

    }
    else if(KEY4==0)
    {
        delay(15);
        if(KEY4==0)
        {
            return 4;
        }
        else
            return 0;

    }
    else if(KEY5==0)
    {
        delay(15);
        if(KEY5==0)
        {
            return 5;
        }
        else
            return 0;
    }
    else
        return 0;
}
void print_dangerous()
{
	write_com(0x01);
    write_com(0x80);
    write_data('D');
    write_data('a');
    write_data('n');
    write_data('g');
    write_data('e');
    write_data('r');
    write_data('o');
    write_data('u');
    write_data('s');
    write_data('!');
}
void sing_danger()
{
	  uchar i=0;
    Timer0init();
    a=danger[i];
    t=danger[i+1];
    while(t)
    {
        song();
        i=i+2;
        a=danger[i];
        t=danger[i+1];
    }
}
void print_resetting()
{
          write_com(0x80);
          write_data('R');
          write_data('e');
	        write_data('s');
	        write_data('t');
	        write_data('t');
	        write_data('i');
	        write_data('n');
	        write_data('g');
	        write_data(' ');
	        write_data('P');
	        write_data('a');
	        write_data('s');
	        write_data('s');
          write_data('w');
          write_data('o');
          write_data('r');
          write_data('d');
}
void resetting()
{
	  uchar i=0;
    int k1=0,k2=0,k3=0,k4=0,k5=0;
    int ke1=1,ke2=1,ke3=1,ke4=1;
	   k5=1;
	   print_resetting();
     while(k5<2)
    {
        if(key_on()==1)
        {
            k1=num[ke1];
            ke1++;
            if(ke1==11)
                ke1=1;
        }
        if(key_on()==2)
        {
            k2=num[ke2];
            ke2++;
            if(ke2==11)
                ke2=1;
        }
        if(key_on()==3)
        {
            k3=num[ke3];
            ke3++;
            if(ke3==11)
                ke3=1;
        }
        if(key_on()==4)
        {
            k4=num[ke4];
            ke4++;
            if(ke4==11)
                ke4=1;
        }
        if(key_on()==5)
        k5++;
        write_com(0x80);
        write_data('*'+k1);
        write_data('*'+k2);
        write_data('*'+k3);
        write_data('*'+k4);
       }
	    	K1='*'+k1;
		    K2='*'+k2;
		    K3='*'+k3;
	    	K4='*'+k4;
			  reset=1;
}
void dangerous()interrupt 2
{
	  if(sign==1)
		{
			resetting();
		}
		else
    {
	   print_dangerous();
	   sing_danger();
		}
}
void sing_open()
{
    uchar i=0;
    Timer0init();
    a=open[i];
    t=open[i+1];
    while(t)
    {
        song();
        i=i+2;
        a=open[i];
        t=open[i+1];
    }
}
void sing_close()
{
    uchar i=0;
    Timer0init();
    a=close[i];
    t=close[i+1];
    while(t)
    {
        song();
        i=i+2;
        a=close[i];
        t=close[i+1];
			LED=~LED;
    }
}
void loading()
{
    LED=1;
    write_com(0x38);
    write_com(0x0c);
    write_com(0x06);
    write_com(0x01);//ÇåÆÁ

    write_com(0x80);
    write_data('L');
    write_data('o');
    write_data('a');
    write_data('i');
    write_data('n');
    write_data('d');
    delay(500);
    write_data('.');
    delay(500);
    write_data('.');
    delay(500);
    write_data('.');
    delay(700);
    write_com(0x01);
    write_com(0x80);
    write_data('*');
    write_data('*');
    write_data('*');
    write_data('*');
}
void print_locked()
{
    write_com(0x01);
    write_com(0x80);
    write_data('L');
    write_data('o');
    write_data('c');
    write_data('k');
    write_data('e');
    write_data('d');
}
void print_wellcome()
{
    write_com(0x01);
    write_com(0x80);
    write_data('W');
    write_data('e');
    write_data('l');
    write_data('l');
    write_data('c');
    write_data('o');
    write_data('m');
    write_data('e');
}
void print_error()
{
    write_com(0x01);
    write_com(0x80);
    write_data('E');
    write_data('r');
    write_data('r');
    write_data('o');
    write_data('r');
}
void main ()
{
    uchar i=0;
    int k1=0,k2=0,k3=0,k4=0,k5=0;
    int ke1=1,ke2=1,ke3=1,ke4=1;
	  sign=0;
	k5=0;
	begin:
    LED=0;
    EA=1;
    INT1=1;
	  EX1=1;
    while(key_on()==0)
        if(key_on()==5)
        {
            k5++;
            loading();
        }
enter:
    ke1=ke2=ke3=ke4=1;
    while(k5<2)
    {
        if(key_on()==1)
        {
            k1=num[ke1];
            ke1++;
            if(ke1==11)
                ke1=1;
        }
        if(key_on()==2)
        {
            k2=num[ke2];
            ke2++;
            if(ke2==11)
                ke2=1;
        }
        if(key_on()==3)
        {
            k3=num[ke3];
            ke3++;
            if(ke3==11)
                ke3=1;
        }
        if(key_on()==4)
        {
            k4=num[ke4];
            ke4++;
            if(ke4==11)
                ke4=1;
        }
        if(key_on()==5)
        k5++;
        write_com(0x80);
        write_data('*'+k1);
        write_data('*'+k2);
        write_data('*'+k3);
        write_data('*'+k4);
    }
    if(k5==2)
    {
        if('*'+k1==K1&&'*'+k2==K2&&'*'+k3==K3&&'*'+k4==K4)
        {
					  sign=1;
            print_wellcome();
            LED=0;
            sing_open();
					if(reset==1)
					goto begin;
        }
        else
        {
            int i;
            print_error();
            m++;
					if(m>3)
        {
            print_locked();
					  while(1);
        }
            k5=1;
				    sing_close();
            for(i=0; i<=20; i++)
            {
                LED=~LED;
                delay(50);
            }
            write_com(0x01);
            goto enter;
        }
    }
}

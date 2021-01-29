#include <reg52.h>
#include <math.h>
sbit led0=P1^0;
sbit led1=P1^1;
sbit led2=P1^2;
sbit led3=P1^3;
sbit led4=P1^4;
sbit led5=P1^5;
sbit led6=P1^6;

sbit LED0=P2^0;
sbit LED1=P2^1;
sbit LED2=P2^2;
sbit LED3=P2^3;
sbit LED4=P2^4;
sbit LED5=P2^5;
sbit LED6=P2^6;

sbit key1=P3^2;
sbit key2=P3^1;
sbit key3=P3^0;
int ledsup[7]= {0,0,0,0,0,0,0};
int ledsdown[7]= {0,0,0,0,0,0,0};
void delay(int x)
{
    int i,j;
    for(i=x; i>0; i--)
        for(j=120; j>0; j--);
}
void light_up(int x,int y)
{
    int i=0;
    while(i<=6)
    {
        ledsup[i]=x%2;
        x=(x-x%2)/2;
        i++;
    }
    i=0;
    while(i<=6)
    {
        ledsdown[i]=y%2;
        y=(y-y%2)/2;
        i++;
    }
    led0=ledsup[0];
    led1=ledsup[1];
    led2=ledsup[2];
    led3=ledsup[3];
    led4=ledsup[4];
    led5=ledsup[5];
    led6=ledsup[6];
    LED0=ledsdown[0];
    LED1=ledsdown[1];
    LED2=ledsdown[2];
    LED3=ledsdown[3];
    LED4=ledsdown[4];
    LED5=ledsdown[5];
    LED6=ledsdown[6];
}
void lightup(int x,int y)
{
    int i=0;
    while(i<=6)
    {
        ledsup[i]=x%2;
        x=(x-x%2)/2;
        i++;
    }
    i=0;
    while(i<=6)
    {
        ledsdown[i]=y%2;
        y=(y-y%2)/2;
        i++;
    }
    led0=fabs(ledsup[0]-1);
    led1=fabs(ledsup[1]-1);
    led2=fabs(ledsup[2]-1);
    led3=fabs(ledsup[3]-1);
    led4=fabs(ledsup[4]-1);
    led5=fabs(ledsup[5]-1);
    led6=fabs(ledsup[6]-1);

    LED0=fabs(ledsdown[0]-1);
    LED1=fabs(ledsdown[1]-1);
    LED2=fabs(ledsdown[2]-1);
    LED3=fabs(ledsdown[3]-1);
    LED4=fabs(ledsdown[4]-1);
    LED5=fabs(ledsdown[5]-1);
    LED6=fabs(ledsdown[6]-1);
}
void light_form(int x)
{
    switch(x)
    {
    case 1:
        light_up(0x77,0xff);
        break;
    case 2:
        light_up(0x73,0xff);
        break;
    case 3:
        light_up(0x71,0xff);
        break;
    case 4:
        light_up(0x70,0xff);
        break;
    case 5:
        light_up(0x70,0x3f);
        break;
    case 6:
        light_up(0x70,0x1f);
        break;
    case 7:
        light_up(0x70,0x0f);
        break;
    case 8:
        light_up(0x70,0x07);
        break;
    case 9:
        light_up(0x70,0x03);
        break;
    case 10:
        light_up(0x70,0x01);
        break;
    case 11:
        light_up(0x70,0x00);
        break;
    case 12:
        light_up(0x30,0x00);
        break;
    case 13:
        light_up(0x10,0x00);
        break;
    case 14:
        light_up(0x00,0x00);
        break;
    default:
        break;
    }
}
void lights_form(int x)
{
    switch(x)
    {
    case 1:
        light_up(0x5d,0x36);
        break;
    case 2:
        light_up(0x36,0x6b);
        break;
    case 3:
        light_up(0x6b,0x5d);
        break;
    default:
        break;
    }
}

void EXT()interrupt 2
{
    int i=0,j=0,x=0;
    while(i<=10)
    {
        light_up(0x00,0x00);
        delay(50);
        light_up(0xff,0xff);
        delay(50);
        i++;
    }
    i=0;
    while(i<=10)
    {
        light_up(0xff,0x00);
        delay(50);
        light_up(0x00,0xff);
        delay(50);
        i++;
    }
    i=0;
    while(i<=3)
    {
        light_up(0x77,0xff);
        delay(50);
        light_up(0x6b,0xff);
        delay(50);
        light_up(0x5d,0xff);
        delay(50);
        light_up(0x3e,0xff);
        delay(50);
        light_up(0xff,0x3e);
        delay(50);
        light_up(0xff,0x5d);
        delay(50);
        light_up(0xff,0x6b);
        delay(50);
        light_up(0xff,0x77);
        delay(50);
        light_up(0xff,0x6b);
        delay(50);
        light_up(0xff,0x5d);
        delay(50);
        light_up(0xff,0x3e);
        delay(50);
        light_up(0x3e,0xff);
        delay(50);
        light_up(0x5d,0xff);
        delay(50);
        light_up(0x6b,0xff);
        delay(50);
        light_up(0x77,0xff);
        delay(50);
        lightup(0x77,0xff);
        delay(50);
        lightup(0x6b,0xff);
        delay(50);
        lightup(0x5d,0xff);
        delay(50);
        lightup(0x3e,0xff);
        delay(50);
        lightup(0xff,0x3e);
        delay(50);
        lightup(0xff,0x5d);
        delay(50);
        lightup(0xff,0x6b);
        delay(50);
        lightup(0xff,0x77);
        delay(50);
        lightup(0xff,0x6b);
        delay(50);
        lightup(0xff,0x5d);
        delay(50);
        lightup(0xff,0x3e);
        delay(50);
        lightup(0x3e,0xff);
        delay(50);
        lightup(0x5d,0xff);
        delay(50);
        lightup(0x6b,0xff);
        delay(50);
        lightup(0x77,0xff);
        delay(50);
        i++;
    }
    j=0;
    while(j<=20)
    {
        i=0;
        while(i<=3)
        {
            lights_form(i);
            delay(30);
            i++;
        }
        j++;
    }

}

void main()
{

    int i=0,j=0;
    int x=0;
    EA=1;
    EX1=1;
    IT1=1;
zero:
    while(1)
    {
        light_up(0x00,0x00);
        delay(500);
        light_up(0xff,0xff);
        delay(500);
        if(key1==0)
            goto first;
        if (key2==0)
            goto secound;
        if (key3==0)
            goto third;

    }
first:
    if (key1==0)
    {
        delay(10);
        if(key1==0)
        {
            while(1)
            {
                light_up(0x77,0xff);
                delay(100);
                light_up(0x6b,0xff);
                delay(100);
                light_up(0x5d,0xff);
                delay(100);
                light_up(0x3e,0xff);
                delay(100);
                light_up(0xff,0x3e);
                delay(100);
                light_up(0xff,0x5d);
                delay(100);
                light_up(0xff,0x6b);
                delay(100);
                light_up(0xff,0x77);
                delay(100);
                if (key2==0)
                    goto secound;
                if (key3==0)
                    goto third;

            }
        }
    }
secound:
    i=0;
    while(i<=13)
    {
        if (key2==0)
        {
            delay(10);
            if (key2==1)
            {
                i++;
                light_form(i);
            }
        }
    }
    goto zero;
third:
    j=0;
    while(j<=3)
    {
        if (key3==0)
        {
            delay(10);
            if (key3==1)
            {
                j++;
                lights_form(j);
            }
        }
    }
    goto zero;
}

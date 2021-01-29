#include <reg52.h>
char count=0;
void Timer0Init()//定时器初始化函数
{
    TMOD=0x01;//设置定时器工作方式
    TH0=(65536-45872)/256;//前8位初始值 共50ms
    TL0=(65536-45872)%256;//后8位初始值
    EA=1;//开启总中断
    ET0=1;//开启定时器0中断
    TR0=1;//启动定时器0
    EX0=1;//外部中断请求标志
    IT0=1;//选择跳变沿触发
}

void EXT()interrupt 0//外部中断0 C语言对应序号 interrupt 0
{
    P2=~P2; //反置P2
}


void Timero()interrupt 1//定时器0 中断 C语言对应序号 interrupt 1
{
    TH0=(65536-45872)/256;//前8位初始值
    TL0=(65536-45872)%256;//后8位初始值
    count++;
    if(count==20)//精确延时 1s
    {
        count=0;
        P2=~P2;
    }
}

void main()
{
    Timer0Init();
    while(1);


}

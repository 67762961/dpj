#include <reg52.h>
sbit key1=P3^1;/*P3^1是单片机的第三组端口的第一个端口
sbit是声明这是一个位操作 可以直接操作P3^1
KEY1就是声明的变量来读取P3^1的电平了*/
sbit led1=P2^0;//是将发光二极管led1接P2口0位端用以控制led1的亮灭
code unsigned char tmpled[8]= {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void delay(int x)
{
    int i,j;
    for(i=x; i>0; i--)
        for(j=110; j>0; j--);
}

void main()
{
    while(1)//其中1代表一个常量表达式，它永远不会等于0，循环会一直执行下去。除非你设置break等类似的跳出循环语句循环才会中止。
    {
        if(key1==0)//判断按钮是否被摁下
        {
            delay(10);
            if(key1==0)//10毫秒后再次确认按钮是否被摁下 以完成消抖防误触
            {
                while(!key1);//如果key1为零 则！key1不为零 执行下列语句
                led1=~led1//使led1电频取反 即高电频转为低电频 即通电开灯
            }

        }

    }


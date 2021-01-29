#include <reg52.h> //52单片机专用头文件
sbit led=P2^0;//定义led灯
code unsigned char tmpled[8]= {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//数组函数
/*
C语言定义函数

dataType  functionName()
{body}
dataType 是返回值类型，它可以是C语言中的任意数据类型，例如 int、float、char 等。
functionName 是函数名，它是标识符的一种，命名规则和标识符相同。函数名后面的括号( )不能少。
body 是函数体，它是函数需要执行的代码，是函数的主体部分。即使只有一个语句，函数体也要由{ }包围。
如果有返回值，在函数体中使用 return 语句返回。return 出来的数据的类型要和 dataType 一样。

C语言定义数组

int arr[10];
int arr[] = {1,2,4};
int arr[10] = {1,2};
int *arr  = new int[10];

一般为
int name[lenth]={a,b,c,d};
{}中数的数量不可超过[]中标示的数组长度，但可少于数组长度，剩余的数将被自动初始化成0。
前三种通用，最后一种只可C++编译
*/

void delay(int x)//定义延时函数
{
    int i,j;
    for(i=x; i>0; i--)//大循环X次 每次都执行一次小循环
        for(j=120; j>0; j--);//小循环100到120次 约为1毫秒
}

void main()
{
    int x=0;
    while(1)
    {
        for(x=0; x<8; x++)
        {
            P2=tmpled[x];//每次循环点亮一个灯
            delay(100);//延迟100毫秒以后 开始下一个点亮模式
        }
    }
}

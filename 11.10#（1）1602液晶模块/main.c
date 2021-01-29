#include<reg52.h>
sbit RW = P2^5;//读写信号
sbit RS = P2^6;//数据命令选择 寄存器选择
sbit E = P2^7;//使能信号 E 受到脉冲 高电平跳变为低电平时 液晶模块执行命令

void delay(int x)//常规单片机延时函数
{
	int i, j;
	for(i = x; i > 0; i--)
	for(j = 110; j > 0; j--);
}

void write_com(char com)//定义函数 显示数据寄存器地址
{
	E = 0;
	RS = 0;
	RW = 0;
	P0 = com;
	delay(1);
	E = 1;//接下来的是给 E 一个脉冲 使刚才的设置生效
	delay(5);
	E = 0;
}

void write_data(char dat)//定义函数 要写的数据内容
{
	E = 0;
	RS = 1;
	RW = 0;
	P0 = dat;
	delay(1);
	E = 1;
	delay(5);//此处延时5ms 停止脉冲 输出字符延时 可增加延时 使字符逐个显示
	E = 0;
}

int main()
{
    //初始化设置
    write_com(0x38);//设置8位数据线 显示两行 5*7的点阵
	write_com(0x0c);//控制显示开关 (打开显示屏)
	write_com(0x06);//每次写入数据 光标右移 整屏不移动
	write_com(0x01);//清屏指令

	write_com(0x80+0x00);//设置初始地址 只有0x00~0x0f 和 0x40~0x4f 可以显示出来
	write_data('L');//定义需要显示的字符 可用asci码 可用16进制表格
	write_data('O');
	write_data('V');
	write_data('E');
	write_data(' ');
	write_data('Y');
	write_data('O');
	write_data('U');

	write_com(0x40);//地址选择第一个自定义字符第贮存器位置 第二个为0x48 共八个可自定义字符

	write_data(0x00);//5*8 的格点 每一行分别用2进制1（亮）0（灭）控制 前面3位补零后 转换成两个16进制数
	write_data(0x00);
	write_data(0x0a);
	write_data(0x15);
	write_data(0x11);
	write_data(0x0a);
	write_data(0x04);
	write_data(0x00);

	write_com(0x89);//选中一个位置显示字符
	write_data(0x00); //从第0个自定义字符寄存器中取出数据 输出至选中位置

	while (1);//1602 数据输入之后就锁存 此句进入死循环 不然重新执行程序会闪烁


}

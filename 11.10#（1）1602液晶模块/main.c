#include<reg52.h>
sbit RW = P2^5;//��д�ź�
sbit RS = P2^6;//��������ѡ�� �Ĵ���ѡ��
sbit E = P2^7;//ʹ���ź� E �ܵ����� �ߵ�ƽ����Ϊ�͵�ƽʱ Һ��ģ��ִ������

void delay(int x)//���浥Ƭ����ʱ����
{
	int i, j;
	for(i = x; i > 0; i--)
	for(j = 110; j > 0; j--);
}

void write_com(char com)//���庯�� ��ʾ���ݼĴ�����ַ
{
	E = 0;
	RS = 0;
	RW = 0;
	P0 = com;
	delay(1);
	E = 1;//���������Ǹ� E һ������ ʹ�ղŵ�������Ч
	delay(5);
	E = 0;
}

void write_data(char dat)//���庯�� Ҫд����������
{
	E = 0;
	RS = 1;
	RW = 0;
	P0 = dat;
	delay(1);
	E = 1;
	delay(5);//�˴���ʱ5ms ֹͣ���� ����ַ���ʱ ��������ʱ ʹ�ַ������ʾ
	E = 0;
}

int main()
{
    //��ʼ������
    write_com(0x38);//����8λ������ ��ʾ���� 5*7�ĵ���
	write_com(0x0c);//������ʾ���� (����ʾ��)
	write_com(0x06);//ÿ��д������ ������� �������ƶ�
	write_com(0x01);//����ָ��

	write_com(0x80+0x00);//���ó�ʼ��ַ ֻ��0x00~0x0f �� 0x40~0x4f ������ʾ����
	write_data('L');//������Ҫ��ʾ���ַ� ����asci�� ����16���Ʊ��
	write_data('O');
	write_data('V');
	write_data('E');
	write_data(' ');
	write_data('Y');
	write_data('O');
	write_data('U');

	write_com(0x40);//��ַѡ���һ���Զ����ַ���������λ�� �ڶ���Ϊ0x48 ���˸����Զ����ַ�

	write_data(0x00);//5*8 �ĸ�� ÿһ�зֱ���2����1������0���𣩿��� ǰ��3λ����� ת��������16������
	write_data(0x00);
	write_data(0x0a);
	write_data(0x15);
	write_data(0x11);
	write_data(0x0a);
	write_data(0x04);
	write_data(0x00);

	write_com(0x89);//ѡ��һ��λ����ʾ�ַ�
	write_data(0x00); //�ӵ�0���Զ����ַ��Ĵ�����ȡ������ �����ѡ��λ��

	while (1);//1602 ��������֮������� �˾������ѭ�� ��Ȼ����ִ�г������˸


}

#include <reg52.h>
char count=0;
void Timer0Init()//��ʱ����ʼ������
{
    TMOD=0x01;//���ö�ʱ��������ʽ
    TH0=(65536-45872)/256;//ǰ8λ��ʼֵ ��50ms
    TL0=(65536-45872)%256;//��8λ��ʼֵ
    EA=1;//�������ж�
    ET0=1;//������ʱ��0�ж�
    TR0=1;//������ʱ��0
    EX0=1;//�ⲿ�ж������־
    IT0=1;//ѡ�������ش���
}

void EXT()interrupt 0//�ⲿ�ж�0 C���Զ�Ӧ��� interrupt 0
{
    P2=~P2; //����P2
}


void Timero()interrupt 1//��ʱ��0 �ж� C���Զ�Ӧ��� interrupt 1
{
    TH0=(65536-45872)/256;//ǰ8λ��ʼֵ
    TL0=(65536-45872)%256;//��8λ��ʼֵ
    count++;
    if(count==20)//��ȷ��ʱ 1s
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

#define _CRT_SECURE_NO_WARNINGS 1

/*
�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����

����Ϊ4�����ɷ��Ĺ���:
    A˵�������ҡ�
    B˵����C��
    C˵����D��
    D˵��C�ں�˵

��֪3����˵���滰��1����˵���Ǽٻ���
�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
*/

#include <stdio.h>
int main()
{
    char killer = 'A';
    for (killer = 'A'; killer <= 'D'; killer++)
    {
        if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
        {
            printf("������%c\n", killer);
        }
    }
    return 0;
}
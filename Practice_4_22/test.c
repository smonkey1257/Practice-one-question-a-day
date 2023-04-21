#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

int main(void)
{
    //��������
    Queue odd;
    QueueInit(&odd);
    //ż������
    Queue even;
    QueueInit(&even);
    //��Ÿ���
    int N = 0;
    scanf("%d", &N);
    int number = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        //�������
        scanf("%d", &number);
        if (number % 2)
        {
            QueuePush(&odd, number);
            count++;
        }
        else
        {
            QueuePush(&even, number);
        }
    }
    //ҵ�����
    Queue new;
    QueueInit(&new);
    switch (count)
    {
    case 0://��������ȫ��
        new.head = even.head;
        break;
    case 1://��������ֻ��1��
        QueuePush(&new, QueueFront(&odd));
        QueuePop(&odd);
        new.tail->next = even.head;
        break;
    case 2://��������ֻ������
        QueuePush(&new, QueueFront(&odd));
        QueuePop(&odd);
        QueuePush(&new, QueueFront(&odd));
        QueuePop(&odd);
        new.tail->next = even.head;
        break;
    default://��������
        while (odd.head && even.head)
        {
            QueuePush(&new, QueueFront(&odd));
            QueuePop(&odd);
            QueuePush(&new, QueueFront(&odd));
            QueuePop(&odd);
            QueuePush(&new, QueueFront(&even));
            QueuePop(&even);
        }
        if (QueueEmpty(&odd))
        {
            new.tail->next = even.head;
        }
        if (QueueEmpty(&even))
        {
            new.tail->next = odd.head;
        }
        break;
    }
    //���
    while (new.head->next)
    {
        printf("%d ", QueueFront(&new));
        QueuePop(&new);
    }
    printf("%d", QueueFront(&new));
    return 0;
}
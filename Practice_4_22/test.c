#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

int main(void)
{
    //奇数队列
    Queue odd;
    QueueInit(&odd);
    //偶数队列
    Queue even;
    QueueInit(&even);
    //编号个数
    int N = 0;
    scanf("%d", &N);
    int number = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        //数据入队
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
    //业务办理
    Queue new;
    QueueInit(&new);
    switch (count)
    {
    case 0://奇数队列全空
        new.head = even.head;
        break;
    case 1://奇数队列只有1个
        QueuePush(&new, QueueFront(&odd));
        QueuePop(&odd);
        new.tail->next = even.head;
        break;
    case 2://奇数队列只有两个
        QueuePush(&new, QueueFront(&odd));
        QueuePop(&odd);
        QueuePush(&new, QueueFront(&odd));
        QueuePop(&odd);
        new.tail->next = even.head;
        break;
    default://大于两个
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
    //输出
    while (new.head->next)
    {
        printf("%d ", QueueFront(&new));
        QueuePop(&new);
    }
    printf("%d", QueueFront(&new));
    return 0;
}
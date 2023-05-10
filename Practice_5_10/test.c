#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef char DataType;

#define STACKSIZE 100 

typedef struct {
    DataType items[STACKSIZE];
    int top;
}SqStack;

int InitStack(SqStack* S)
{ // ��ʼ��˳��ջ
    S->top = -1;
    return 1;
}

int StackEmpty(SqStack S)
{ // ��ջ��
    if (S.top == -1)    return 1;
    else    return 0;
}

int Push(SqStack* S, DataType e)
{ // ѹջ����
    if (S->top >= STACKSIZE - 1) {
        return 0;
    }
    S->top++;
    S->items[S->top] = e;
    return 1;
}

int Pop(SqStack* S, DataType* e)
{ // ��ջ����
    if (S->top <= -1) {
        return 0;
    }
    *e = S->items[S->top];
    S->top--;
    return 1;
}

int TraverseStack(SqStack S)
{ // ����˳��ջ
    int i;
    for (i = 0; i < S.top + 1; i++)
        printf("%d ", S.items[i]);
    return 1;
}

/* ����Ҫ������������tempջ��һ���ǿ�ջs1������Ԫ�ذ�ԭ�����Ƶ���һ��ջs2����ȥ */
int CopyStack(SqStack S1, SqStack* S2, SqStack temp);

int  main()
{
    int i, input;
    SqStack S1, S2, temp; //����˳��ջ
    InitStack(&S1);//��ʼ������ջ
    InitStack(&S2);
    InitStack(&temp);
    for (i = 0;; i++)
    {
        scanf("%d", &input);  // ĳЩ������Ҫ��˴���Ϊscanf_s
        if (input == -1)break;
        Push(&S1, input);
    }
    CopyStack(S1, &S2, temp);
    TraverseStack(S2);//����
    return 0;
}

/* ����������д�� */
int CopyStack(SqStack S1, SqStack* S2, SqStack temp)
{
    DataType x = 0;

    //S1 ���Ƶ� temp
    while (!StackEmpty(S1))
    {
        //��ջ
        Pop(&S1, &x);
        //��ջ
        Push(&temp, x);
    }

    //temp ���Ƶ� S2
    while (!StackEmpty(temp))
    {
        //��ջ
        Pop(&temp, &x);
        //��ջ
        Push(S2, x);
    }
    return 1;
}
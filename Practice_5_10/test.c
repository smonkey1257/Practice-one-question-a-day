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
{ // 初始化顺序栈
    S->top = -1;
    return 1;
}

int StackEmpty(SqStack S)
{ // 判栈空
    if (S.top == -1)    return 1;
    else    return 0;
}

int Push(SqStack* S, DataType e)
{ // 压栈函数
    if (S->top >= STACKSIZE - 1) {
        return 0;
    }
    S->top++;
    S->items[S->top] = e;
    return 1;
}

int Pop(SqStack* S, DataType* e)
{ // 弹栈函数
    if (S->top <= -1) {
        return 0;
    }
    *e = S->items[S->top];
    S->top--;
    return 1;
}

int TraverseStack(SqStack S)
{ // 遍历顺序栈
    int i;
    for (i = 0; i < S.top + 1; i++)
        printf("%d ", S.items[i]);
    return 1;
}

/* 本题要求函数——利用temp栈将一个非空栈s1的所有元素按原样复制到另一个栈s2当中去 */
int CopyStack(SqStack S1, SqStack* S2, SqStack temp);

int  main()
{
    int i, input;
    SqStack S1, S2, temp; //定义顺序栈
    InitStack(&S1);//初始化建空栈
    InitStack(&S2);
    InitStack(&temp);
    for (i = 0;; i++)
    {
        scanf("%d", &input);  // 某些编译器要求此处改为scanf_s
        if (input == -1)break;
        Push(&S1, input);
    }
    CopyStack(S1, &S2, temp);
    TraverseStack(S2);//遍历
    return 0;
}

/* 请在这里填写答案 */
int CopyStack(SqStack S1, SqStack* S2, SqStack temp)
{
    DataType x = 0;

    //S1 复制到 temp
    while (!StackEmpty(S1))
    {
        //出栈
        Pop(&S1, &x);
        //入栈
        Push(&temp, x);
    }

    //temp 复制到 S2
    while (!StackEmpty(temp))
    {
        //出栈
        Pop(&temp, &x);
        //入栈
        Push(S2, x);
    }
    return 1;
}
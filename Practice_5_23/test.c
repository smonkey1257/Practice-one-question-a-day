#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { addq, delq, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
typedef struct QNode* PtrToQNode;
struct QNode {
    ElementType* Data;  /* 存储元素的数组   */
    Position Front;     /* 队列的头、尾指针 */
    int Count;          /* 队列中元素个数   */
    int MaxSize;        /* 队列最大容量     */
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    Q->Front = 0;
    Q->Count = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool AddQ(Queue Q, ElementType X);
ElementType DeleteQ(Queue Q);

Operation GetOp();  /* 裁判实现，细节不表 */

int main()
{
    ElementType X;
    Queue Q;
    int N, done = 0;

    scanf("%d", &N);
    Q = CreateQueue(N);
    while (!done) {
        switch (GetOp()) {
        case addq:
            scanf("%d", &X);
            AddQ(Q, X);
            break;
        case delq:
            X = DeleteQ(Q);
            if (X != ERROR) printf("%d is out\n", X);
            break;
        case end:
            while (Q->Count) printf("%d ", DeleteQ(Q));
            done = 1;
            break;
        }
    }
    return 0;
}

/* 你的代码将被嵌在这里 */

//在这道题中front指向的位置是空的，队首为front的下一个位置
//队首：Q->Front=(Q->Front+1)%Q->MaxSize
//队尾：Q->Rear=(Q->Front+Q->Count)%Q->MaxSize

//如果队列已满，AddQ函数必须输出“Queue Full”并且返回false
bool AddQ(Queue Q, ElementType X)
{
    if (Q->Count == Q->MaxSize)
    {
        printf("Queue Full\n");
        return false;
    }
    else//未满就入队
    {
        //队头的下标是一直会变大的，因此要取余
        ++Q->Count;
        Q->Data[(Q->Front + Q->Count) % Q->MaxSize] = X;
        return true;
    }
}

//如果队列是空的，则DeleteQ函数必须输出“Queue Empty”，并且返回ERROR
ElementType DeleteQ(Queue Q)
{
    if (Q->Count == 0)
    {
        printf("Queue Empty\n");
        return ERROR;
    }
    else
    {
        //先获取对头再删除
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        Q->Count--;
        return Q->Data[Q->Front];
    }
}
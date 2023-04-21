#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//初始化队列
void QueueInit(Queue* q)
{
    assert(q);
    q->head = NULL;
    q->tail = NULL;
}
//销毁队列
void QueueDestroy(Queue* q)
{
    assert(q);
    assert(!QueueEmpty(q));

    QueueNode* cur = q->head;
    while (cur)
    {
        QueueNode* tmp = cur;
        cur = cur->next;
        free(tmp);
        tmp = NULL;
    }
    q->head = q->tail = NULL;
}
//队列判空
int QueueEmpty(Queue* q)
{
    assert(q);
    return q->head == NULL;
}
//入队
void QueuePush(Queue* q, QDataType data)
{
    assert(q);

    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->data = data;
    newnode->next = NULL;

    if (QueueEmpty(q))
        q->head = q->tail = newnode;
    else
    {
        q->tail->next = newnode;
        q->tail = q->tail->next;
    }
}
//出队
void QueuePop(Queue* q)
{
    assert(q);
    assert(!QueueEmpty(q));

    QueueNode* tmp = q->head;
    q->head = q->head->next;
    free(tmp);
    tmp = NULL;

    if (q->head == NULL)
        q->tail = NULL;
}
//获取队头元素
QDataType QueueFront(Queue* q)
{
    assert(q);
    assert(!QueueEmpty(q));
    return q->head->data;
}
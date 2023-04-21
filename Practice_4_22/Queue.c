#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//��ʼ������
void QueueInit(Queue* q)
{
    assert(q);
    q->head = NULL;
    q->tail = NULL;
}
//���ٶ���
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
//�����п�
int QueueEmpty(Queue* q)
{
    assert(q);
    return q->head == NULL;
}
//���
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
//����
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
//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q)
{
    assert(q);
    assert(!QueueEmpty(q));
    return q->head->data;
}
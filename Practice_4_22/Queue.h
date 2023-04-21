#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int QDataType;
typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;
}QueueNode;
typedef struct Queue
{
    struct QueueNode* head;
    struct QueueNode* tail;
}Queue;

//��ʼ������
void QueueInit(Queue* q);

//���ٶ���
void QueueDestroy(Queue* q);

//�����п�
int QueueEmpty(Queue* q);

//���
void QueuePush(Queue* q, QDataType data);

//����
void QueuePop(Queue* q);

//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q);
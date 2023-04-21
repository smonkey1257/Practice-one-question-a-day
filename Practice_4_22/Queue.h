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

//初始化队列
void QueueInit(Queue* q);

//销毁队列
void QueueDestroy(Queue* q);

//队列判空
int QueueEmpty(Queue* q);

//入队
void QueuePush(Queue* q, QDataType data);

//出队
void QueuePop(Queue* q);

//获取队头元素
QDataType QueueFront(Queue* q);
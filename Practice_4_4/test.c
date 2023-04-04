#define _CRT_SECURE_NO_WARNINGS 1

/*
给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。

输入格式:
输入首先给出一个正整数K，随后是若干非负整数，最后以一个负整数表示结尾（该负数不算在序列内，不要处理）。

输出格式:
输出倒数第K个位置上的数据。如果这个位置不存在，输出错误信息NULL。
*/

#include <stdio.h>
#include <stdlib.h>
//节点创建
struct node
{
    int data;
    struct node* next;
};
int main(void)
{
    //指针变量声明
    struct node* head = NULL;
    //输入k
    int k = 0;
    (void)scanf("%d", &k);
    //输入链表
    int num = 0;
    while (~scanf("%d", &num) && num >= 0)
    {
        //创建新节点存放数据
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            exit(-1);
        }
        newnode->data = num;
        newnode->next = NULL;

        //头插
        newnode->next = head;
        head = newnode;
    }
    //头插相当于将输入样例翻转，倒数第k个节点，相当于顺数第k个节点
    //头插完后，再遍历找到第k个节点
    int i = 0;
    for (i = 0; i < k - 1; i++)
    {
        head = head->next;
    }
    //输出
    if (head)
        printf("%d", head->data);
    else
        printf("NULL");
    return 0;
}
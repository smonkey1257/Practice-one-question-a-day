#define _CRT_SECURE_NO_WARNINGS 1

/*
����һϵ���������������һ�������ܸ�Ч���㷨�����ҵ�����K��λ���ϵ����֡�

�����ʽ:
�������ȸ���һ��������K����������ɷǸ������������һ����������ʾ��β���ø��������������ڣ���Ҫ������

�����ʽ:
���������K��λ���ϵ����ݡ�������λ�ò����ڣ����������ϢNULL��
*/

#include <stdio.h>
#include <stdlib.h>
//�ڵ㴴��
struct node
{
    int data;
    struct node* next;
};
int main(void)
{
    //ָ���������
    struct node* head = NULL;
    //����k
    int k = 0;
    (void)scanf("%d", &k);
    //��������
    int num = 0;
    while (~scanf("%d", &num) && num >= 0)
    {
        //�����½ڵ�������
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            exit(-1);
        }
        newnode->data = num;
        newnode->next = NULL;

        //ͷ��
        newnode->next = head;
        head = newnode;
    }
    //ͷ���൱�ڽ�����������ת��������k���ڵ㣬�൱��˳����k���ڵ�
    //ͷ������ٱ����ҵ���k���ڵ�
    int i = 0;
    for (i = 0; i < k - 1; i++)
    {
        head = head->next;
    }
    //���
    if (head)
        printf("%d", head->data);
    else
        printf("NULL");
    return 0;
}
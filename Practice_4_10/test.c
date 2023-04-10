#define _CRT_SECURE_NO_WARNINGS 1

/*
��Ŀ��һԪ����ʽ�ĳ˷���ӷ�����

�����ʽ:
�����2�У�ÿ�зֱ��ȸ�������ʽ������ĸ���������ָ���ݽ���ʽ����һ������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���

�����ʽ:
�����2�У��ֱ���ָ���ݽ���ʽ����˻�����ʽ�Լ��Ͷ���ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո������ʽӦ���0 0��

����������
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1

���������
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��������ʽ�ڵ�
typedef struct Polynomial
{
    int coefficient;
    int index;
    struct Polynomial* next;
}Polynomial;

Polynomial* PolynomialInit()
{
    // k Ϊ����
    int k = 0;
    scanf("%d", &k);

    //�������������һ���������洢�����������ͷָ��
    Polynomial* head = NULL, * tail = NULL;

    while (k--)
    {
        //�����½ڵ������
        Polynomial* newnode = (Polynomial*)malloc(sizeof(Polynomial));
        scanf("%d %d", &newnode->coefficient, &newnode->index);
        newnode->next = NULL;

        //�������Ϊ��
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
    }
    return head;
}

Polynomial* PolynomialProduct(Polynomial* A, Polynomial* B)
{
    //�����ƽ⣬����������
    Polynomial* newhead = NULL, *newtail = NULL;
    Polynomial* Ahead = A, * Atail = A;
    Polynomial* Bhead = B, * Btail = B;

    while (Btail)
    {
        while (Atail)
        {
            Polynomial* tmp = (Polynomial*)malloc(sizeof(Polynomial));
            tmp->coefficient = Atail->coefficient * Btail->coefficient;
            tmp->index = Atail->index + Btail->index;
            tmp->next = NULL;
            if (newhead == NULL)
            {
                newhead = newtail = tmp;
            }
            else
            {
                newtail->next = tmp;
                newtail = newtail->next;
            }
            Atail = Atail->next;
        }
        Atail = Ahead;
        Btail = Btail->next;
    }
    return newhead;
}


// �������ӡ
void SLPrint(Polynomial* plist)
{
    //�ڲ�Ϊ��ָ��֮ǰ
    while (plist)
    {
        printf("%d %d ", plist->coefficient, plist->index);
        plist = plist->next;
    }
    //�����ʾ��ָ�벢�һ���
    printf("-> NULL\n");
}
//����Ҫ�Ķ�������˲���Ҫ����ָ��

int main()
{
    //A����ʽ
    Polynomial* A = PolynomialInit();
    //B����ʽ
    Polynomial* B = PolynomialInit();
    ////����ʽ�˻�

    Polynomial* Product = PolynomialProduct(A, B);
    ////����ʽ֮��
    //Polynomial* sum = PolynomialSum(A, B);
    ////��ӡ
    SLPrint(Product);

    return 0;
}
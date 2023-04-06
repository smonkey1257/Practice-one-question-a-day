
/*
(leetcode)21. �ϲ�������������

��������������ϲ�Ϊһ���µ� ���� �������ء�
��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //�ж������б��Ƿ��п��б�
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    //��������ָ�����
    struct ListNode* head = NULL, * tail = NULL;
    //��һ���ڵ�
    if (list1->val < list2->val)
    {
        head = list1;
        tail = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        tail = list2;
        list2 = list2->next;
    }
    //�����б���Ϊ��
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    //����һ���б��Ѿ��ϲ���ϣ�ֱ�ӽ�ʣ�µ�һ����������
    if (list1)
    {
        tail->next = list1;
    }
    if (list2)
    {
        tail->next = list2;
    }
    return head;
}
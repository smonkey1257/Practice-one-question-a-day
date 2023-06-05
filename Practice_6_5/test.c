#define _CRT_SECURE_NO_WARNINGS 1

/*
* ɾ�����������е��ظ���㣨�������83��
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head) {
    //������
    if (head == NULL)
        return head;

    struct ListNode* prev = head;
    struct ListNode* next = head->next;

    while (next)
    {
        //ɾ���ظ����
        if (next->val == prev->val)
        {
            prev->next = next->next;
            free(next);
            next = prev->next;
        }
        else
        {
            prev = next;
            next = next->next;
        }
    }
    //curΪ��˵�������Ѿ��������
    return head;
}
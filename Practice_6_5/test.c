#define _CRT_SECURE_NO_WARNINGS 1

/*
* 删除有序链表中的重复结点（力扣题号83）
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head) {
    //空链表
    if (head == NULL)
        return head;

    struct ListNode* prev = head;
    struct ListNode* next = head->next;

    while (next)
    {
        //删除重复结点
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
    //cur为空说明链表已经遍历完毕
    return head;
}
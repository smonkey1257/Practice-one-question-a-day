#define _CRT_SECURE_NO_WARNINGS 1

/*���������������*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
void _inorder(struct TreeNode* root, int* ret, int* returnSize)
{
    if (root)
    {
        _inorder(root->left, ret, returnSize);
        ret[(*returnSize)++] = root->val;
        _inorder(root->right, ret, returnSize);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;//һ��Ҫ��ʼ����
    int* ret = (int*)malloc(sizeof(int) * 101);
    _inorder(root, ret, returnSize);
    return ret;
}
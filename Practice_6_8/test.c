#define _CRT_SECURE_NO_WARNINGS 1

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
void _postorder(struct TreeNode* root, int* returnSize, int* ret)
{
    if (root)
    {
        _postorder(root->left, returnSize, ret);
        _postorder(root->right, returnSize, ret);
        ret[(*returnSize)++] = root->val;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    _postorder(root, returnSize, ret);
    return ret;
}
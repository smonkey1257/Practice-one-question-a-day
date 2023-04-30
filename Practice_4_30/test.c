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

  //将遍历到的数据放到数组里面，第一个问题：数组的空间大小是多少？
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//将数据存到数组，就要操纵下标，因此传下标，还是传下标的地址
void _prevOrder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
    {
        return;
    }

    a[*pi] = root->val;
    ++(*pi);
    _prevOrder(root->left, a, pi);
    _prevOrder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * size);

    int i = 0;
    _prevOrder(root, a, &i);

    //输出型参数returnSize
    *returnSize = size;

    return a;
}
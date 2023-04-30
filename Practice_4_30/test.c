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

  //�������������ݷŵ��������棬��һ�����⣺����Ŀռ��С�Ƕ��٣�
int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//�����ݴ浽���飬��Ҫ�����±꣬��˴��±꣬���Ǵ��±�ĵ�ַ
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

    //����Ͳ���returnSize
    *returnSize = size;

    return a;
}
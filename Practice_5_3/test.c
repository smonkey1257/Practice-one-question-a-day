#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char BTDataType;
typedef struct BinaryTreeNode {
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

//后序遍历
void  PostOrder(BTNode* root)
{
    if (root)
    {

        PostOrder(root->left);
        PostOrder(root->right);
        printf("%c", root->data);
    }
}

//先序 + 中序建立二叉树
BTNode* CreatBinaryTree(char* pre, char* in, int n)
{
    BTNode* root = NULL;
    int i = 0;
    if (n <= 0) 
        return NULL;
    if (!(root = (BTNode*)malloc(sizeof(BTNode))))
        exit(-1);
    root->data = pre[0];
    for (i = 0; in[i] != pre[0]; i++);
    root->left = CreatBinaryTree(pre + 1, in, i);
    root->right = CreatBinaryTree(pre + i + 1, in + i + 1, n - i - 1);
    //先序：根 + 左 + 右
    //中序：左 + 根 + 右
    //前i个属于根 + 左子树的节点，对于右子树来说要跳过，右子树序列的长度为n-i-1;
    return root;
}

int main()
{
    BTNode* root = NULL;
    char prelist[100] = { 0 };
    char inlist[100] = { 0 };
    int length = 0;

    (void)scanf("%s", prelist);
    (void)scanf("%s", inlist);
    length = strlen(prelist);

    //创建二叉树
    root = CreatBinaryTree(prelist, inlist, length);

    //后序遍历
    PostOrder(root);
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//树的节点
typedef char DataType;
typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    DataType data;
}TNode;

//前序创建树
TNode* CreateTree(char* ch, int* pi)
{
    if (ch[*pi] == '#')
    {
        ++(*pi);
        return NULL;
    }

    //根
    TNode* root = (TNode*)malloc(sizeof(TNode));
    root->data = ch[*pi];
    ++(*pi);

    //左, 右
    root->left = CreateTree(ch, pi);
    root->right = CreateTree(ch, pi);

    return root;
}

//中序遍历
void InOrder(TNode* root)
{
    if (root == NULL)
        return;

    InOrder(root->left);

    if (root->data != '#')
        printf("%c ", root->data);

    InOrder(root->right);
}

int main() {
    //输入包括1行字符串，长度不超过100
    char ch[100] = { 0 };
    scanf("%s", ch);

    //前序建立二叉树
    int i = 0;
    TNode* root = CreateTree(ch, &i);//数组要下标，下标要地址

    //中序遍历
    InOrder(root);

    return 0;
}
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

//�������
void  PostOrder(BTNode* root)
{
    if (root)
    {

        PostOrder(root->left);
        PostOrder(root->right);
        printf("%c", root->data);
    }
}

//���� + ������������
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
    //���򣺸� + �� + ��
    //������ + �� + ��
    //ǰi�����ڸ� + �������Ľڵ㣬������������˵Ҫ���������������еĳ���Ϊn-i-1;
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

    //����������
    root = CreatBinaryTree(prelist, inlist, length);

    //�������
    PostOrder(root);
    return 0;
}
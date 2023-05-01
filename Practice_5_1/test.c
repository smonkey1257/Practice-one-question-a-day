#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//���Ľڵ�
typedef char DataType;
typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    DataType data;
}TNode;

//ǰ�򴴽���
TNode* CreateTree(char* ch, int* pi)
{
    if (ch[*pi] == '#')
    {
        ++(*pi);
        return NULL;
    }

    //��
    TNode* root = (TNode*)malloc(sizeof(TNode));
    root->data = ch[*pi];
    ++(*pi);

    //��, ��
    root->left = CreateTree(ch, pi);
    root->right = CreateTree(ch, pi);

    return root;
}

//�������
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
    //�������1���ַ��������Ȳ�����100
    char ch[100] = { 0 };
    scanf("%s", ch);

    //ǰ����������
    int i = 0;
    TNode* root = CreateTree(ch, &i);//����Ҫ�±꣬�±�Ҫ��ַ

    //�������
    InOrder(root);

    return 0;
}
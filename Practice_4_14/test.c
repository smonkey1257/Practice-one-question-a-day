#define _CRT_SECURE_NO_WARNINGS 1

/*
7-1 ��ջ�����Ϸ���
���� 37
���� DS�γ���
��λ �㽭��ѧ
������S��X�ֱ��ʾ��ջ�ͳ�ջ������
�������һ������S��X���ɵ����У���һ���ն�ջ���в�������Ӧ���������У���û�г���ɾ��ʱջ�գ������״̬Ҳ��ջ�գ�
��Ƹ������ǺϷ��Ķ�ջ�������С����д��������S��X���У��жϸ������Ƿ�Ϸ���

�����ʽ:
�����һ�и�������������N��M������N�Ǵ������еĸ�����M����50���Ƕ�ջ�����������
���N�У�ÿ���и���һ������S��X���ɵ����С����б�֤��Ϊ�գ��ҳ��Ȳ�����100��

�����ʽ:
��ÿ�����У���һ�������YES����������ǺϷ��Ķ�ջ�������У���NO������ǡ�

����������
4 10
SSSXXSXXSX
SSSXXSXXS
SSSSSSSSSSXSSXXXXXXXXXXX
SSSXXSXXX

*/

//ɾ��ʱջ��Ϊ�� �� ���ջΪ��

#include <stdio.h>
#include <string.h>
#define MAX 100
int main(void)
{
    int N = 0, M = 0, i = 0;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        //ÿ��һ������
        char arr[MAX] = { 0 };
        scanf("%s", arr);

        int count = 0;

        int len = strlen(arr);
        int j = 0;
        for (j = 0; j < len; j++)
        {
            //�����ַ���
            if (arr[j] == 'S')
                count++;
            else
                count--;
            //�������������count����ջ����
            if (count > M)
            {
                count = 1;
                break;
            }
            //ջΪ�ջ�����ɾ������
            if (count < 0)
            {
                count = 1;
                break;
            }
        }
        //�ж�
        if (!count)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1

//X形图案
#include <stdio.h>
int main() {
    int num = 0;
    while (~scanf("%d", &num))
    {
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                if (j == i || j + i == (num - 1))
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}


//带空格直角三角形图案
#include <stdio.h>
int main() {
    int num = 0;
    while (~scanf("%d", &num))
    {
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                if (j + i >= num - 1)
                    printf("* ");
                else
                    printf("  ");
            }
            printf("\n");
        }
    }
    return 0;
}

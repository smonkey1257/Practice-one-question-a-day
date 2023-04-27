#define _CRT_SECURE_NO_WARNINGS 1

//常用头文件包含
#include <stdio.h>

//非递归实现斐波那契(不考虑溢出)
int Fibonacci1(unsigned int n)
{
	int f1 = 1;
	int f2 = 1;
	int f = 1;
	while (n >= 3)
	{
		f = f1 + f2;

		f1 = f2;
		f2 = f;
		n--;
	}
	return f;
}

//递归实现斐波那契
int Fibonacci2(unsigned int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fibonacci2(n - 1) + Fibonacci2(n - 2);
	}
}

//递归实现n的k次方
//底数n随意，但k必须为整数（无论正负）
double myPow(double n, int k)
{
	if (k >= 0)
		return k == 0 ? 1.0 : n * myPow(n, k - 1);
	else
		return k == 0 ? 1.0 : (1.0 / n) * myPow(n, k + 1);
}

//计算一个非负整数的每位之和（递归实现）
unsigned int DigitSum(unsigned int n)
{
	//写法一：
	//if (n > 9)
	//	return (n % 10) + DigitSum(n / 10);
	//else
	//	return n % 10;

	//写法二：
	return n > 9 ? (n % 10) + DigitSum(n / 10) : (n % 10);
}

//实现字符串逆序
void reverse_string(char* string)
{
	//如果没有这一步就会在偶数个字符的情况下会把中间的两个字符的的前一个字符置为'\0',导致字符串结束
	if (*string == '\0')
		return;
	
	//找到最后一个字符（非'\0'）
	char* left = string;
	char* right = NULL;
	int i = 0;
	for (i = 0; left[i] != '\0'; i++)
		;
	right = left + i - 1;
	
	//交换
	char tmp = *left;
	if (left < right)
	{
		*left = *right;
		*right = '\0';
		reverse_string(string + 1);
	}
	//回归过程中覆盖'\0'完成交换
	*right = tmp;
}

//非递归模拟strlen
unsigned int myStrlen1(char* string)
{
	unsigned int count = 0;
	while (*string != '\0')
	{
		count++;
		string++;
	}
	return count;
}

//递归模拟实现strlen
unsigned int myStrlen(char* string)
{
	return *string == '\0' ? 0 : myStrlen(string + 1) + 1;
}

//非递归实现N的阶乘（不考虑溢出）
unsigned int fac1(unsigned int n)
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

//递归实现N的阶乘（不考虑溢出）
unsigned int fac2(unsigned int n)
{
	return (n == 1 || n == 0) ? 1 : n * fac2(n - 1);
}

//递归实现打印整数的每一位
void print(int n)
{
	if (n > 9)
		print(n / 10);

	printf("%d ", n % 10);
}

//测试第一题函数
void test1()
{
	unsigned int n = 0;
	scanf("%u", &n);
	printf("结果为%d\n", Fibonacci1(n));//过
	printf("结果为%d\n", Fibonacci2(n));//过

	//测试完成
}

//测试第二题函数
void test2()
{
	double n = 0;
	int k = 0;
	scanf("%lf %u", &n, &k);
	printf("结果为%lf\n", myPow(n, k));
	//测试完成
}

//第三题
void test3()
{
	unsigned int n = 1234;
	printf("和为%u\n", DigitSum(n));
	//测试完成
}

//第四题
void test4()
{
	char ch[] = "abcdef";
	reverse_string(ch);
	printf("%s", ch);
	//测试完成
}

//第五题
void test5()
{
	printf("%u\n", myStrlen("hello bit"));
	//测试完成
	printf("%u\n", fac1(0));
	printf("%u\n", fac2(1));

	print(1234);
}

int main(void)
{

	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}
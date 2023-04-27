#define _CRT_SECURE_NO_WARNINGS 1

//����ͷ�ļ�����
#include <stdio.h>

//�ǵݹ�ʵ��쳲�����(���������)
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

//�ݹ�ʵ��쳲�����
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

//�ݹ�ʵ��n��k�η�
//����n���⣬��k����Ϊ����������������
double myPow(double n, int k)
{
	if (k >= 0)
		return k == 0 ? 1.0 : n * myPow(n, k - 1);
	else
		return k == 0 ? 1.0 : (1.0 / n) * myPow(n, k + 1);
}

//����һ���Ǹ�������ÿλ֮�ͣ��ݹ�ʵ�֣�
unsigned int DigitSum(unsigned int n)
{
	//д��һ��
	//if (n > 9)
	//	return (n % 10) + DigitSum(n / 10);
	//else
	//	return n % 10;

	//д������
	return n > 9 ? (n % 10) + DigitSum(n / 10) : (n % 10);
}

//ʵ���ַ�������
void reverse_string(char* string)
{
	//���û����һ���ͻ���ż�����ַ�������»���м�������ַ��ĵ�ǰһ���ַ���Ϊ'\0',�����ַ�������
	if (*string == '\0')
		return;
	
	//�ҵ����һ���ַ�����'\0'��
	char* left = string;
	char* right = NULL;
	int i = 0;
	for (i = 0; left[i] != '\0'; i++)
		;
	right = left + i - 1;
	
	//����
	char tmp = *left;
	if (left < right)
	{
		*left = *right;
		*right = '\0';
		reverse_string(string + 1);
	}
	//�ع�����и���'\0'��ɽ���
	*right = tmp;
}

//�ǵݹ�ģ��strlen
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

//�ݹ�ģ��ʵ��strlen
unsigned int myStrlen(char* string)
{
	return *string == '\0' ? 0 : myStrlen(string + 1) + 1;
}

//�ǵݹ�ʵ��N�Ľ׳ˣ������������
unsigned int fac1(unsigned int n)
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

//�ݹ�ʵ��N�Ľ׳ˣ������������
unsigned int fac2(unsigned int n)
{
	return (n == 1 || n == 0) ? 1 : n * fac2(n - 1);
}

//�ݹ�ʵ�ִ�ӡ������ÿһλ
void print(int n)
{
	if (n > 9)
		print(n / 10);

	printf("%d ", n % 10);
}

//���Ե�һ�⺯��
void test1()
{
	unsigned int n = 0;
	scanf("%u", &n);
	printf("���Ϊ%d\n", Fibonacci1(n));//��
	printf("���Ϊ%d\n", Fibonacci2(n));//��

	//�������
}

//���Եڶ��⺯��
void test2()
{
	double n = 0;
	int k = 0;
	scanf("%lf %u", &n, &k);
	printf("���Ϊ%lf\n", myPow(n, k));
	//�������
}

//������
void test3()
{
	unsigned int n = 1234;
	printf("��Ϊ%u\n", DigitSum(n));
	//�������
}

//������
void test4()
{
	char ch[] = "abcdef";
	reverse_string(ch);
	printf("%s", ch);
	//�������
}

//������
void test5()
{
	printf("%u\n", myStrlen("hello bit"));
	//�������
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
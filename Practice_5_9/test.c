#define _CRT_SECURE_NO_WARNINGS 1

//��תһ������ֽ��бȽ�
bool isPalindrome(int x) {
    //���ǻ�����
    if ((x < 0) || (x % 10 == 0 && x != 0))
        return false;

    int reverseNumber = 0;
    //�ǻ�����
    while (x > reverseNumber)
    {
        reverseNumber = reverseNumber * 10 + x % 10;
        x /= 10;
    }
    return (x == reverseNumber / 10) || (x == reverseNumber);
}
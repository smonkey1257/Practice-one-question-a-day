#define _CRT_SECURE_NO_WARNINGS 1

//反转一半的数字进行比较
bool isPalindrome(int x) {
    //不是回文数
    if ((x < 0) || (x % 10 == 0 && x != 0))
        return false;

    int reverseNumber = 0;
    //是回文数
    while (x > reverseNumber)
    {
        reverseNumber = reverseNumber * 10 + x % 10;
        x /= 10;
    }
    return (x == reverseNumber / 10) || (x == reverseNumber);
}
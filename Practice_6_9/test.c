#define _CRT_SECURE_NO_WARNINGS 1

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int pnum1 = m - 1;
    int pnum2 = n - 1;
    int end = nums1Size - 1;

    //pnum1 == -1
    if (pnum1 == -1)
    {
        while (pnum2 >= 0)
        {
            nums1[end--] = nums2[pnum2--];
        }
    }
    //pnum2 == -1
    else if (pnum2 == -1);
    //pnum1 != -1 && pnum2 != -1
    else
    {
        while (pnum2 >= 0 && pnum1 >= 0)
        {
            if (nums2[pnum2] >= nums1[pnum1])
            {
                nums1[end--] = nums2[pnum2--];
            }
            else
            {
                nums1[end--] = nums1[pnum1--];
            }
        }
        if (pnum1 == -1)
            while (pnum2 >= 0)
                nums1[end--] = nums2[pnum2--];
        else if (pnum2 == -1)
            while (pnum1 >= 0)
                nums1[end--] = nums1[pnum1--];
    }

}
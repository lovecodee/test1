#include<iostream>
#include<stdio.h>
using namespace std;
#define N 100

void QuickSorted(int a[], int begin, int end);        //快排算法

int main()
{
    int n;
    int a[N];
    printf("请输入排序元素总个数：\n");
    cin >> n;
    printf("请输入元素:\n");
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    QuickSorted(a, 1, n);
    printf("排序后的结果为:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;

}

void QuickSorted(int a[], int begin, int end)
{
    int i, j;
    int temp = a[begin];
    if (begin < end)
    {
        i = begin;
        j = end;
        while (i < j)
        {
            while (a[j] > temp) { j--; }
                a[i]=a[j];
            while (a[++i] < temp) { i++; }
                a[j]=a[i]; j--;
        }
        if(i==j)
        {
            a[i] = temp;
        }
        QuickSorted(a, begin, i-1);
        QuickSorted(a, i + 1, end);
    }
}

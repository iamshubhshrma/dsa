#include <stdio.h>
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high - 1;
    while (a[i] < pivot)
    {
        i++;
    }
    while (a[j] > pivot)
    {
        j--;
    }
    if (i < j)
    {
        swap(a[j], a[i]);
    }
    swap(a[j], pivot);
    return j;
}

void quick(int a[], int low, int high)
{
    if (low < high)
    {
        int m = partition(a, low, high);
        quick(a, low, m - 1);
        quick(a, m + 1, high);
    }
}
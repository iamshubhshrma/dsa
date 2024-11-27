#include <stdio.h>
int a[6] = {3, 2, 5, 1, 6, 4};
int main()
{
    int n = 6;
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d", a[i]);
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d", a[i]);
    }
}

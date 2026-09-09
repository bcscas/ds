#include <stdio.h>
int getMax(int a[], int n)
{
    int max = a[0], i;
    for(i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];
    return max;
}
void countSort(int a[], int n, int exp)
{
    int b[10], c[10] = {0}, i;

    for(i = 0; i < n; i++)
        c[(a[i] / exp) % 10]++;

    for(i = 1; i < 10; i++)
        c[i] += c[i - 1];

    for(i = n - 1; i >= 0; i--)
        b[--c[(a[i] / exp) % 10]] = a[i];

    for(i = 0; i < n; i++)
        a[i] = b[i];
}
void radixSort(int a[], int n)
{
    int max = getMax(a, n), exp;
    for(exp = 1; max / exp > 0; exp *= 10)
        countSort(a, n, exp);
}
int main()
{
    int a[10], n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixSort(a, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

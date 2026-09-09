#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int l = 2*i+1, r = 2*i+2, max = i, t;

    if(l < n && a[l] > a[max])
        max = l;
    if(r < n && a[r] > a[max])
        max = r;

    if(max != i)
    {
        t = a[i];
        a[i] = a[max];
        a[max] = t;
        heapify(a, n, max);
    }
}

int main()
{
    int a[10], n, i, t;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = n/2-1; i >= 0; i--)
        heapify(a, n, i);

    for(i = n-1; i > 0; i--)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

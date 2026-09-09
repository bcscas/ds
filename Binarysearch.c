#include <stdio.h>

int main()
{
    int a[10], n, i, key, low, high, mid;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            printf("Found at index %d", mid);
            return 0;
        }
        else if(key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Not found");
    return 0;
}

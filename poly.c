#include <stdio.h>
#include <conio.h>
int main()
{
    int a[10], b[10], c[10], m, n, i, max;
    clrscr();
    printf("Enter degree of first polynomial: ");
    scanf("%d", &m);
    printf("Enter coefficients of first polynomial:\nA=");
    for(i = 0; i <= m; i++)
        scanf("%d", &a[i]);
     printf("Enter degree of second polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficients of second polynomial:\nB=");
    for(i = 0; i <= n; i++)
        scanf("%d", &b[i]);

    max = (m > n) ? m : n;
    for(i = 0; i <= max; i++)
        c[i] = (i <= m ? a[i] : 0) + (i <= n ? b[i] : 0);

    printf("\nResultant Polynomial Coefficients:\n");
    for(i = max; i >= 0; i--)
    {
        printf("%dx^%d ", c[i], i);
        if(i) printf("+ ");
    }
    getch();
    return 0;
}
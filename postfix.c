#include <stdio.h>
#include <ctype.h>
#include <conio.h>

int main()
{
    int stack[50], top = -1, i, op1, op2, result;
    char postfix[50], ch;
    clrscr();
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    for(i = 0; (ch = postfix[i]) != '\0'; i++)
    {
        if(isdigit(ch))
            stack[++top] = ch - '0';
        else
        {
            op2 = stack[top--];
            op1 = stack[top--];
            switch(ch)
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            stack[++top] = result;
        }
    }
    printf("Result = %d\n", stack[top]);
    getch();
    return 0;
}
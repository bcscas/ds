#include <stdio.h>
#include <conio.h>

int main()
{
    int stack[5], top = -1, choice, item, i;

    clrscr();

    do
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(top == 4)
                    printf("Stack Overflow\n");
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &item);
                    stack[++top] = item;
                }
                break;
            case 2:
                if(top == -1)
                    printf("Stack Underflow\n");
                else
                    printf("Deleted element: %d\n", stack[top--]);
                break;
            case 3:
                if(top == -1)
                    printf("Stack is empty\n");
                else
                    printf("Top element: %d\n", stack[top]);
                break;
            case 4:
                if(top == -1)
                    printf("Stack is empty\n");
                else
                {
                    printf("Stack elements are:\n");
                    for(i = top; i >= 0; i--)
                        printf("%d\n", stack[i]);
                }
                break;
            case 5:
                printf("Program Ended\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while(choice != 5);
    getch();
    return 0;
}
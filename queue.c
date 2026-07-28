#include <stdio.h>
#include <conio.h>

int main()
{
    int queue[5], front = -1, rear = -1;
    int choice, item, i;
    clrscr();
    do
    {
        printf("\n1. Enqueue (Insert)\n2. Dequeue (Delete)\n3. Peek (Front)\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(rear == 4)
                    printf("Queue Overflow\n");
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &item);
                    if(front == -1) front = 0;
                    queue[++rear] = item;
                    printf("Inserted successfully\n");
                }
                break;
            case 2:
                if(front == -1 || front > rear)
                    printf("Queue Underflow\n");
                else
                    printf("Deleted element = %d\n", queue[front++]);
                break;
            case 3:
                if(front == -1 || front > rear)
                    printf("Queue is empty\n");
                else
                    printf("Front element = %d\n", queue[front]);
                break;
            case 4:
                if(front == -1 || front > rear)
                    printf("Queue is empty\n");
                else
                {
                    printf("Queue elements are:\n");
                    for(i = front; i <= rear; i++)
                        printf("%d ", queue[i]);
                    printf("\n");
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
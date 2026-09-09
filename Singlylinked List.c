#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int ch, val;

    do {
        printf("\n1.Insert Begin  2.Insert End");
        printf("\n3.Delete Begin  4.Delete End");
        printf("\n5.Display  6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
        case 1:
            newnode = malloc(sizeof(struct node));
            printf("Enter value: ");
            scanf("%d", &val);
            newnode->data = val;
            newnode->next = head;
            head = newnode;
            break;

        case 2:
            newnode = malloc(sizeof(struct node));
            printf("Enter value: ");
            scanf("%d", &val);
            newnode->data = val;
            newnode->next = NULL;

            if(head == NULL)
                head = newnode;
            else {
                temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = newnode;
            }
            break;

        case 3:
            if(head == NULL)
                printf("List Empty\n");
            else {
                temp = head;
                head = head->next;
                free(temp);
            }
            break;

        case 4:
            if(head == NULL)
                printf("List Empty\n");
            else if(head->next == NULL) {
                free(head);
                head = NULL;
            }
            else {
                temp = head;
                while(temp->next->next != NULL)
                    temp = temp->next;
                free(temp->next);
                temp->next = NULL;
            }
            break;

        case 5:
            temp = head;
            while(temp != NULL) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
            break;

        case 6:
            printf("Program Ended");
            break;

        default:
            printf("Invalid Choice");
        }
    } while(ch != 6);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

void inorder(struct node *r) {
    if(r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct node *r) {
    if(r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node *r) {
    if(r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

int main() {
    struct node *root = NULL, *p;
    int ch, val;

    do {
        printf("\n1.Root  2.Left  3.Right");
        printf("\n4.Inorder  5.Preorder  6.Postorder  7.Exit");
        printf("\nChoice: ");
        scanf("%d",&ch);

        switch(ch) {
        case 1:
            root = malloc(sizeof(struct node));
            printf("Value: ");
            scanf("%d",&root->data);
            root->left = root->right = NULL;
            break;

        case 2:
            if(root) {
                p = malloc(sizeof(struct node));
                printf("Value: ");
                scanf("%d",&p->data);
                p->left = p->right = NULL;
                root->left = p;
            } else printf("Create root first\n");
            break;

        case 3:
            if(root) {
                p = malloc(sizeof(struct node));
                printf("Value: ");
                scanf("%d",&p->data);
                p->left = p->right = NULL;
                root->right = p;
            } else printf("Create root first\n");
            break;

        case 4:
            printf("Inorder: ");
            inorder(root);
            break;

        case 5:
            printf("Preorder: ");
            preorder(root);
            break;

        case 6:
            printf("Postorder: ");
            postorder(root);
            break;

        case 7:
            printf("Program Ended");
            break;

        default:
            printf("Invalid Choice");
        }
    } while(ch != 7);

    return 0;
}

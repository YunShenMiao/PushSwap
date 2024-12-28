typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}   node;

#include <stdio.h>
#include <stdlib.h>

void revrotate_list(node **node1)
{
    node *current;
    node *tail;
    node *afterhead;

    if(*node1 == NULL || node1 == NULL || (*node1)->next == 0)
    return;
    current = (*node1);
    afterhead = (*node1);
    while (current->next != NULL)
        current = current->next;
    current->next = afterhead;
    afterhead->prev = current;
    tail = current->prev;
    tail->next = NULL;
    current->prev = NULL;
    *node1 = current;
}


/* void print_list(node *head) {
    node *current = head;

    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
} */


/* int main()
{
    node *node1 = malloc(sizeof(node));
    node *node2 = malloc(sizeof(node));
    node *node3 = malloc(sizeof(node));
    node *node4 = malloc(sizeof(node));
    int a = 1;
    int b = 2;
    int c = 3;

    node1->data = a;
    node2->data = b;
    node1->prev = NULL;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->data = c;
    node3->prev = node2;
    node3->next = node4;
    node4->data = 4;
    node4->prev = node3;
    node4->next = NULL;
    print_list(node1);
    revrotate_list(&node1);
    print_list(node1);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    return(0);
} */
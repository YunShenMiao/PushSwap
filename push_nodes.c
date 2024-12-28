typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}   node;

#include <stdio.h>
#include <stdlib.h>

void push_nodes(node **topush, node **dest)
{
    node *tempa;
    node *tempb;
    node *anext;

    if (topush == NULL || *topush == NULL)
    return;
    tempa = *topush;
    tempb = *dest;
    anext = (*topush)->next;

    tempa->next = tempb;
    anext->prev = NULL;

    *topush = anext;
    *dest = tempa;
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
    node *nodea = malloc(sizeof(node));
    node *nodeb = malloc(sizeof(node));
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

    nodea->data = 9;
    nodeb->data = 8;
    nodea->prev = NULL;
    nodea->next = nodeb;
    nodeb->prev = nodea;
    nodeb->next = NULL;
    printf("stack a: ");
    print_list(node1);
    printf("stack b: ");
    print_list(nodea);
    push_nodes(&node1, &nodea);
    printf("stack a: ");
    print_list(node1);
    printf("stack b: ");
    print_list(nodea);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(nodea);
    free(nodeb);
    return(0);
} */
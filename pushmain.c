
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}   node;

#include <stdio.h>
#include <stdlib.h> 

void swapsi(node **node1);
void push_nodes(node **a1, node **b1);
void revrotate_list(node **node1);
void rotate_list(node **node1);

void print_list(node *head) {
    node *current = head;

    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
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

    /* nodea->data = 9;
    nodeb->data = 8;
    nodea->prev = NULL;
    nodea->next = nodeb;
    nodeb->prev = nodea;
    nodeb->next = NULL; */
    nodea = NULL;

    printf("original lists: \n");
    print_list(node1);
    print_list(nodea);
    swapsi(&node1);
    swapsi(&nodea);
    printf("after swap: \n");
    print_list(node1);
    print_list(nodea);
    rotate_list(&node1);
    rotate_list(&nodea);
    printf("after rotate: \n");
    print_list(node1);
    print_list(nodea);
    revrotate_list(&node1);
    revrotate_list(&nodea);
    printf("after reverse rotate: \n");
    print_list(node1);
    print_list(nodea);
    push_nodes(&node1, &nodea);
    printf("after push: \n");
    print_list(node1);
    print_list(nodea);
    push_nodes(&node1, &nodea);
    printf("after push2: \n");
    print_list(node1);
    print_list(nodea);
    swapsi(&node1);
    swapsi(&nodea);
    printf("after swap: \n");
    print_list(node1);
    print_list(nodea);
    push_nodes(&nodea, &node1);
    printf("after push (otherway): \n");
    print_list(node1);
    print_list(nodea);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    return(0);
}
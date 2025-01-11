#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct s_node {
    int data;
    struct s_node *next;
    struct s_node *prev; // Optional: for a doubly linked list
} t_node;

// Function to create a new node
t_node *create_node(int data) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL; // Initialize prev to NULL
    return new_node;
}

// Function to append a node to the end of the list
void append_node(t_node **head, int data) {
    t_node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    t_node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp; // Set the previous pointer
}

// Function to print the list
void print_list(t_node *head) {
    t_node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the list
void free_list(t_node *head) {
    t_node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Your list_sorted function
int list_sorted(t_node **stack) {
    t_node *temp;

    if (stack == NULL || *stack == NULL) {
        return 0; // Consider an empty list as not sorted
    }

    temp = *stack;
    if (temp->next == NULL)
        return 1;

    while (temp->next != NULL) {
        if (temp->data > temp->next->data)
            break;
        temp = temp->next;
    }
    if (temp->next == NULL)
        return 1;

    temp = *stack;
    while (temp->next != NULL) {
        if (temp->data < temp->next->data)
            break;
        temp = temp->next;
    }
    if (temp->next == NULL)
        return -1;

    return 0;
}

int main() {
    t_node *stack = NULL;

    // Create a sorted ascending list
    printf("Testing ascending sorted list:\n");
    for (int i = 1; i <= 10; i++) {
        append_node(&stack, i); // Append numbers 1 to 10
    }
    printf("List: ");
    print_list(stack);
    printf("Sorted status: %d\n", list_sorted(&stack)); // Should return 1 (ascending)

    // Free the list
    free_list(stack);
    stack = NULL;

    // Create a sorted descending list
    printf("\nTesting descending sorted list:\n");
    for (int i = 10; i >= 1; i--) {
        append_node(&stack, i); // Append numbers 10 to 1
    }
    printf("List: ");
    print_list(stack);
    printf("Sorted status: %d\n", list_sorted(&stack)); // Should return -1 (descending)

    // Free the list
    free_list(stack);
    stack = NULL;

    // Create an unsorted list
    printf("\nTesting unsorted list:\n");
    append_node(&stack, 1);
    append_node(&stack, 5);
    append_node(&stack, 3);
    append_node(&stack, 8);
    append_node(&stack, 2);
    append_node(&stack, 7);
    append_node(&stack, 4);
    append_node(&stack, 6);
    append_node(&stack, 10);
    append_node(&stack, 9);
    printf("List: ");
    print_list(stack);
    printf("Sorted status: %d\n", list_sorted(&stack)); // Should return 0 (not sorted)

    // Free the list
    free_list(stack);
    stack = NULL;

    // Create another unsorted list with more elements
    printf("\nTesting another unsorted list:\n");
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0) {
            append_node(&stack, i); // Append even numbers
        } else {
            append_node(&stack, 21 - i); // Append odd numbers in reverse order
        }
    }
    printf("List: ");
    print_list(stack);
    printf("Sorted status: %d\n", list_sorted(&stack)); // Should return 0 (not sorted)

    // Free the list
    free_list(stack);
    return 0;
}
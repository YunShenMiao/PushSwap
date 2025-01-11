/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:21:45 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/11 11:54:54 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_list(t_node **node1)
{
    t_node *current;
    t_node *temphead;
    t_node *temptail;

    if (*node1 == NULL || node1 == NULL || (*node1)->next == NULL)
    return;
    temphead = (*node1)->next;
    temptail = *node1;
    current = *node1;
    /* printf("head: %d tail: %d", temphead->data, temptail->data); */
    while (current->next != NULL)
    {
        current->tail = temptail;
        current = current->next;
    }
    current->tail = temptail;
    current->next = temptail;
    temptail->prev = current;
    temptail->next = NULL;
    temphead->prev = NULL;

    *node1=temphead;
}

void ra(t_node **node1)
{
    rotate_list(node1);
    ft_printf("ra\n");
}

void rb(t_node **node1)
{
    rotate_list(node1);
    ft_printf("rb\n");
}

void rr(t_node **node1, t_node **node2)
{
    rotate_list(node1);
    rotate_list(node2);
    ft_printf("rr\n");
}

/* void print_list(t_node *head) {
    t_node *current = head;

    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_nodes(t_node **head)
{
    while(*head != NULL)
    {
        free(*head);
        *head = (*head)->next;
    }
}

int main()
{
    t_node *node1 = malloc(sizeof(node));
    t_node *node2 = malloc(sizeof(node));
    t_node *node3 = malloc(sizeof(node));
    t_node *node4 = malloc(sizeof(node));
    t_node *nodea = malloc(sizeof(node));
    if (!node1 || !node2 || !node3 || !node4 || !nodea)
    return(1);

    node1->data = 1;
    node2->data = 2;
    node1->prev = NULL;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->data = 3;
    node3->prev = node2;
    node3->next = node4;
    node4->data = 4;
    node4->prev = node3;
    node4->next = NULL;

    nodea->data = 10;
    nodea->prev = NULL;
    nodea->next = NULL;
    
    print_list(node1);
    print_list(nodea);
    rr(&node1, &nodea);
    print_list(node1);
    print_list(nodea);
    free_nodes(&node1);
    free_nodes(&nodea);
    return(0);
} */
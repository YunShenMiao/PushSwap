/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:17:41 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/18 15:33:25 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_nodes(t_node **topush, t_node **dest)
{
    t_node *tempa;
    t_node *tempb;
    t_node *anext;

    if (topush == NULL || *topush == NULL)
    return;
 
    tempa = *topush;
    tempb = *dest;
    anext = (*topush)->next;

    tempa->next = tempb;
    if (tempb == NULL)
    tempa->tail = tempa;
    else
    { 
    tempa->tail = tempb->tail;
    tempb->prev = tempa;
    }
    if (anext != NULL)
    anext->prev = NULL;

    *topush = anext;
    *dest = tempa;
}

void pa(t_node **topush, t_node **dest)
{
    push_nodes(topush, dest);
    ft_printf("pa\n");
}

void pb(t_node **topush, t_node **dest)
{
    push_nodes(topush, dest);
    ft_printf("pb\n");
}

/* void print_list(t_node *head) 
{
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
    t_node *nodeb = malloc(sizeof(node));


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
    pa(&node1, &nodea);
    printf("stack a: ");
    print_list(node1);
    printf("stack b: ");
    print_list(nodea);

    printf("stack a: ");
    print_list(node1);
    printf("stack b: ");
    print_list(nodea);
    pb(&nodea, &node1);
    printf("stack a: ");
    print_list(node1);
    printf("stack b: ");
    print_list(nodea);
    
    free_nodes(&node1);
    free_nodes(&nodea);
    return(0);
} */
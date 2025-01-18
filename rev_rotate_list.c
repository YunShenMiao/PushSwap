/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:20:11 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/18 15:37:09 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_rotate_list(t_node **node1)
{
    t_node *current;
    t_node *ttail;
    t_node *afterhead;

    if(node1 == NULL || *node1 == NULL || (*node1)->next == NULL)
    return;
    current = (*node1);
    afterhead = (*node1);
    while (current->next != NULL)
        current = current->next;
    current->next = afterhead;
    ttail = current->prev;
    afterhead->prev = current;
    current->prev = NULL;
    ttail->next = NULL;
    *node1 = current;
    t_node *temp = *node1;
    while (temp->next != NULL)
    {
        temp->tail = ttail;
        temp = temp->next;
    }
    /* printf("%d", (*node1)->tail->data); */
}


void rra(t_node **node1)
{
    rev_rotate_list(node1);
    ft_printf("rra\n");
}

void rrb(t_node **node1)
{
    rev_rotate_list(node1);
    ft_printf("rrb\n");
}

void rrr(t_node **node1, t_node **node2)
{
    rev_rotate_list(node1);
    rev_rotate_list(node2);
    ft_printf("rrr\n");
}
/* 
 void print_list(t_node *head) {
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

t_node	*create_node(int data)
{
	t_node *newnode;
    
    newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->tail = newnode;
	return (newnode);
}

void update_tail(t_node *head, t_node *new_tail)
{
	t_node *temp;

	temp = head;
	while (temp)
	{
		temp->tail = new_tail;
		temp = temp->next;
	}
}

int	insert_end(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = create_node(data);
	if (!new_node)
		return (-1);
	if ((*head) == NULL)
		*head = new_node;
	else
	{
		temp = (*head);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	new_node->next = NULL;
	update_tail(*head, new_node);
	return(1);
}

int main()
{
    t_node *node1 = create_node(1);
    insert_end(&node1, 2);
    insert_end(&node1, 3);
    insert_end(&node1, 4);
    
    if (!node1)
    return(1);
    
    print_list(node1);
    rev_rotate_list(&node1);
    print_list(node1);
    free_nodes(&node1);
    return(0);
} */
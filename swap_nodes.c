/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:22:41 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/30 18:44:01 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapsi(t_node **node1)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*temp3;

	if (*node1 == NULL || node1 == NULL || (*node1)->next == NULL)
		return ;
	temp1 = *node1;
	temp2 = (*node1)->next;
	temp3 = temp2->next;
	temp1->prev = temp2;
	temp2->next = temp1;
	temp1->next = temp3;
	if (temp3 != NULL)
	temp3->prev = temp1;
	temp2->prev = NULL;
	*node1 = temp2;
}

void	sa(t_node **node1)
{
	swapsi(node1);
	ft_printf("sa\n");
}

void	sb(t_node **node1)
{
	swapsi(node1);
	ft_printf("sb\n");
}

void	ss(t_node **node1, t_node **node2)
{
	swapsi(node1);
	swapsi(node2);
	ft_printf("ss\n");
}

/* void print_list(node *head) {
	node *current = head;

	printf("Doubly Linked List: ");
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void free_nodes(node **head)
{
    while(*head != NULL)
    {
        free(*head);
        *head = (*head)->next;
    }
}

int	main(void)
{
	node *node1 = malloc(sizeof(node));
	node *node2 = malloc(sizeof(node));
    node *node3 = malloc(sizeof(node));
    node *node5 = malloc(sizeof(node));
    node *node6 = malloc(sizeof(node));
        if (!node1 || !node2 || !node3 || !node5 || !node6)
    return(1);

	node1->data = 1;
	node2->data = 2;
    node3->data = 3;
	node1->prev = NULL;
	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
    node3->prev = node2;
    node3->next = NULL;
    
    node5->data = 10;
    node6->data = 20;
    node5->prev = NULL;
    node5->next = node6;
    node6->prev = node5;
    node6->next = NULL;
    
	print_list(node1);
    print_list(node5);
	ss(&node1, &node5);
    print_list(node1);
	print_list(node5);
	free_nodes(&node1);
    free_nodes(&node5);
	return(0);
} */
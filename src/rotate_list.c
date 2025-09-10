/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:21:45 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/19 14:54:50 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_list(t_node **node1)
{
	t_node	*current;
	t_node	*temphead;
	t_node	*temptail;

	if (*node1 == NULL || node1 == NULL || (*node1)->next == NULL)
		return ;
	temphead = (*node1)->next;
	temptail = *node1;
	current = *node1;
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
	*node1 = temphead;
}

void	ra(t_node **node1)
{
	rotate_list(node1);
	ft_printf("ra\n");
}

void	rb(t_node **node1)
{
	rotate_list(node1);
	ft_printf("rb\n");
}

void	rr(t_node **node1, t_node **node2)
{
	rotate_list(node1);
	rotate_list(node2);
	ft_printf("rr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:22:41 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/19 14:50:23 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

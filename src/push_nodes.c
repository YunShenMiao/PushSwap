/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:17:41 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/19 14:55:13 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_nodes(t_node **topush, t_node **dest)
{
	t_node	*tempa;
	t_node	*tempb;
	t_node	*anext;

	if (topush == NULL || *topush == NULL)
		return ;
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

void	pa(t_node **topush, t_node **dest)
{
	push_nodes(topush, dest);
	ft_printf("pa\n");
}

void	pb(t_node **topush, t_node **dest)
{
	push_nodes(topush, dest);
	ft_printf("pb\n");
}

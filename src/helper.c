/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:36:46 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/19 14:58:37 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_len(t_node *stacka)
{
	t_node	*temp;
	int		count;

	if (stacka == NULL)
		return (0);
	temp = stacka;
	count = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	count++;
	return (count);
}

int	r_sqrt(t_node **a)
{
	int	calc;

	calc = 1;
	while (calc * calc < stack_len(*a))
		calc++;
	return (calc * 15 / 10);
}

void	update_tail(t_node *head, t_node *new_tail)
{
	t_node	*temp;

	temp = head;
	while (temp)
	{
		temp->tail = new_tail;
		temp = temp->next;
	}
}

int	list_sorted(t_node **stack)
{
	t_node	*temp;

	temp = (*stack);
	if (temp->next == NULL)
		return (1);
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			break ;
		temp = temp->next;
	}
	if (temp->next == NULL)
		return (1);
	temp = (*stack);
	while ((temp->next != NULL))
	{
		if (temp->data < temp->next->data)
			break ;
		temp = temp->next;
	}
	if (temp->next == NULL)
		return (-1);
	return (0);
}

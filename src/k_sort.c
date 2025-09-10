/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:17:06 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/24 13:15:21 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	distance(t_node **b)
{
	int	head_dist;
	int	tail_dist;

	head_dist = (*b)->next->data - (*b)->data;
	tail_dist = (*b)->tail->data - (*b)->data;
	if (head_dist < 0)
		head_dist = -head_dist;
	if (tail_dist < 0)
		tail_dist = -tail_dist;
	tail_dist = tail_dist + 1;
	if (tail_dist < head_dist)
		return (1);
	return (0);
}

int	direction(t_node **stack, int len)
{
	int		ct;
	int		ch;
	t_node	*temp;

	ct = 0;
	ch = 1;
	temp = (*stack);
	while (temp->data != len - 1)
	{
		temp = temp->next;
		ct++;
	}
	temp = (*stack)->tail;
	while (temp->data != len - 1)
	{
		temp = temp->prev;
		ch++;
	}
	if (ct < ch)
		return (1);
	else
		return (-1);
}

void	sort_back(t_node **a, t_node **b)
{
	int	len;

	while (stack_len(*a) != 0)
		pb(a, b);
	while ((*b)->next != NULL)
	{
		len = stack_len(*b);
		if ((*b)->data != len - 1 && (*b)->next->data != len - 1)
		{
			if (direction(b, len) > 0)
				while ((*b)->data != len - 1)
					rb(b);
			if (direction(b, len) < 0)
				while ((*b)->data != len - 1)
					rrb(b);
		}
		if ((*b)->next->data > (*b)->data)
			sb(b);
		pa(b, a);
		if ((*a)->next != NULL && (*a)->data > (*a)->next->data)
			sa(a);
	}
	pa(b, a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	tail_distance(t_node **a, t_node **b, int r)
{
	if ((*b)->data < (*b)->tail->data)
	{
		rrb(b);
		sb(b);
		if ((*a)->data > r + stack_len(*b))
			rr(a, b);
		else
			rb(b);
	}
	if ((*a)->data > r + stack_len(*b))
		rr(a, b);
	else
		rb(b);
}

void	k_sort(t_node **a, t_node **b)
{
	int	r;

	while ((*a)->next != NULL)
	{
		r = r_sqrt(a);
		if ((*a)->data <= r + stack_len(*b))
		{
			pb(a, b);
			if (stack_len(*b) >= 3 && distance(b) == 1)
				tail_distance(a, b, r);
			else if (stack_len(*b) >= 3 && (*b)->data < (*b)->next->data)
				sb(b);
		}
		else
			ra(a);
	}
	sort_back(a, b);
}

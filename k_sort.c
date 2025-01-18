/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:17:06 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/18 19:43:39 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(t_node **a)
{
	int	calc;

	calc = 1;
	while (calc * calc < stack_len(*a))
		calc++;
	return ((int)calc);
}

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
    if (tail_dist < head_dist)
		return (1);
	return (0);
}

/* void sort_five(t_node **stack, int order)
{
    if (order < 0)
    {
        while (list_sorted(stack) != -1)
        {
            if ((*stack)->data == 0)
            rb(stack);
            else if((*stack)->data < (*stack)->next->data)
            sb(stack);
            else rb(stack);
        }
    }
    else if (order > 0)
    {
        while (list_sorted(stack) != 1)
        {
            if ((*stack)->data == 5)
            ra(stack);
            else if ((*stack)->data > (*stack)->next->data)
            sa(stack);
            else
            ra(stack);
        }
 }
} */

int calc_moves(t_node **stack, int len)
{
    int ct;
    int ch;
    t_node *temp;

    ct = 0;
    ch = 1;
    temp = (*stack);
    while (temp->data != len-1)
    {
        temp = temp->next;
        ct++;
    }
    temp = (*stack)->tail;
    while (temp->data != len-1)
    {
        temp = temp->prev;
        ch++;
    }
    if (ct < ch)
    return(1);
    else
    return(-1);
}

void	sort_back(t_node **a, t_node **b)
{
    int len;
    int direction;

    while (stack_len(*a) != 0)
        pb(a, b);
    while ((*b)->next != NULL)
	{
        len = stack_len(*b);
        if ((*b)->data != len -1 && (*b)->next->data != len - 1)
        {
        direction= calc_moves(b, len);
        if (direction > 0)
            while ((*b)->data != len - 1)
                rb(b);
        if (direction < 0)
            while ((*b)->data != len - 1)
            rrb(b);
        }
        if ((*b)->next->data > (*b)->data
			&& (*b)->next->data > (*b)->tail->data)
		{
			sb(b);
			pa(b, a);
		}
		else if ((*b)->tail->data > (*b)->data)
			pa(b, a);
		else
			pa(b, a);
        if ((*a)->next != NULL && (*a)->data > (*a)->next->data)
			sa(a);
/*         if (stack_len(*b) == 5)
        sort_five(b, -1); */
	}
    pa(b, a);
    if ((*a)->data > (*a)->next->data)
    sa(a);
}

void	k_sort(t_node **a, t_node **b)
{
	int	r;

	while ((*a)->next != NULL)
	{
		r = ft_sqrt(a);
		if ((*a)->data <= r + stack_len(*b))
		{
			pb(a, b);
			if (stack_len(*b) >= 3 && distance(b) == 1)
			{
                if ((*b)->data < (*b)->tail->data)
                {
                    rrb(b);
                    sb(b);
                    rb(b);
                }
				rb(b);
			}
			else if (stack_len(*b) >= 3 && (*b)->data < (*b)->next->data)
				sb(b);
		}
		else
			ra(a);
	}
	sort_back(a, b);
}

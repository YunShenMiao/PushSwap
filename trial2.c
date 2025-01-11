/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trial2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:17:31 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/11 15:51:47 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_len(t_node *stacka)
{
	t_node	*temp;
	int		count;

	temp = stacka;
	count = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	count++;
	return(count);
}

int find_pivot(t_node **stack)
{
    t_node *temp;
    int piv;
    int count;

    temp = (*stack);
    piv = 0;
    count = 0;
    while (temp->next != NULL)
    {
        piv = piv + temp->data;
        temp = temp->next;
        count++;
    }
    piv = piv + temp->data;
    count++;
    if ((piv % count) == 0)
    piv = piv / count;
    else
    piv = piv / (count - 1);
    ft_printf("pipi:%d\n", piv);
    return(piv);
}

/* void quick_sort( t_node **a, t_node **b)
{
    int piva;
    int pivb;

    if (stack_len(*a) <= 3 && stack_len(*b) <= 3)
    return;

    
    
    
} */

void try_sort(t_node **a, t_node **b)
{
    int piv;
    int count;
    int total_len;

    if (stack_len(*a) <= 3)
    return;
    piv = find_pivot(a);
    count = 0;
    total_len = stack_len(*a);
/*     if (stack_len(*a) <= 6)
    piv = piv;
    else
    { */
        while (count < total_len)
        { 
        if ((*a)->data < piv)
        pb(a, b);
        else
        ra(a);
        count++;

        ft_printf("a:%d\n", (*a)->data);
        /* ft_printf("b:%d\n", (*b)->data); */
        ft_printf("piv:%d\n", piv);
        ft_printf("ALEN:%d\n", stack_len(*a));
        ft_printf("count:%d\n", count);
        } 
        ft_printf("doIreach?\n");
        /* try_sort(a, b); */
        try_sort(b, a);
    }

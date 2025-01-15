/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trial3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:01:30 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/15 09:44:02 by jwardeng         ###   ########.fr       */
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

int calc_dist(t_node **stack)
{
    t_node *temp;
    int count;

    temp = (*stack);
    count = 0;
    if (stack_len(*stack) == 3)
    return(0);
    while ((temp->next != NULL) && ((*stack)->data < temp->next->data))
    {
        count++;
        temp = temp->next; 
    }
    return(count);
}

void handle_distance(t_node **b, int calc)
{
    int count;

    count = 0;
            if ((calc = calc_dist(b)) > 1 && calc < (stack_len(*b) - calc))  
               while(1)
            {
                sb(b);
                rb(b);
                count ++;
                if (count == calc/* ((*b)->data > (*b)->next->data) && ((*b)->data < (*b)->tail->data) */)
                {
                while (--count >= 0)
                rrb(b);
                if (list_sorted(b) == -1)
                break;
                }
            }
            else if ((calc = calc_dist(b)) > 1 && !((*b)->data < (*b)->tail->data))
            {
            while(1)
            {
                rrb(b);
                sb(b);
                count++;
                if (/* count == stack_len(*b) - calc */ ((*b)->data > (*b)->next->data) && ((*b)->data < (*b)->tail->data))
                {
                while(--count >= -1)
                rb(b);
                }
                if (list_sorted(b) == -1)
                break;
            }
}
}

void sort_end(t_node **stack, int piv)
{
    t_node *temp;

    temp = (*stack);
    /* if ((*stack)->tail->data > (*stack)->data) */
    rra(stack);
    while((*stack)->next->next->data > piv)
    {
        if ((*stack)->data > (*stack)->next->data && (*stack)->next->data > piv)
        sa(stack);
        if ((*stack)->data < (*stack)->next->data && (*stack)->next->next->data > piv) 
        ra(stack);  
    }
    while ((*stack)->tail->data > piv)
    {
        rra(stack);
        if((*stack)->data > (*stack)->next->data)
        sa(stack);
    }
    while((*stack)->data > piv)
    {
        ra(stack);
    }
}

void sort_stacks(t_node **a, t_node **b)
{
    int calc;
    int piv;
    
    piv = find_pivot(a);
    while (list_sorted(a) == 0)
    {
        if ((*a)->data > piv && (*a)->data > (*a)->tail->data)
        ra(a);
        else if ((*a)->data > piv)
        sort_end(a, piv);
        else if (/* (*a)->data < (*a)->next->data && (*a)->data < (*a)->tail->data &&  */(*a)->data < piv)
        pb(a, b);
        else
        sa(a);
        if(((*b) != NULL) && ((*b)->next != NULL))
        {
            if ((calc = calc_dist(b)) > 1 && !((*b)->data < (*b)->tail->data))
            handle_distance(b, calc);
            else if (((*b)->data < (*b)->next->data) && ((*b)->data > (*b)->tail->data) /* && ((*b)->next->next != NULL) && ((*b)->next->next->data < (*b)->data) */)
            sb(b);
            else if (((*b)->data < (*b)->tail->data) && ((*b)->next != NULL))
            rb(b);
        }
    }
}

void try_sort(t_node **a, t_node **b)
{
   sort_stacks(a, b);  
    while ((*b) != NULL)
    {
        pa(b, a);
/*         if ((*a)->data > (*a)->next->data)
        sa(a); */
    }
}
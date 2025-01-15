/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:33:51 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/15 18:50:44 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_pivot(t_node **stack)
{
    t_node *temp;
    int piv;
    int count;
    
    if (!stack || !(*stack))
    return (0);
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
    piv = piv / count;
    /* ft_printf("pipi:%d\n", piv); */
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
                ft_printf("taily:%d\n", (*b)->tail->data);
                rrb(b);
                ft_printf("miao0\n");
                sb(b);
                count++;
                ft_printf("miao1\n");
                if (/* count == stack_len(*b) - calc */ ((*b)->data > (*b)->next->data) && ((*b)->data < (*b)->tail->data))
                {
                while(--count >= -1)
                rb(b);
                ft_printf("miao2\n");
                }
                ft_printf("miao3\n");
                if (list_sorted(b) == -1)
                break;
            }
}
}

void party(t_node **a, t_node **b, int piv)
{
    int size;
    int count;
    int moves;
    int calc;

    size = stack_len(*a);
    count = 0;
    moves = 0;
    while (count < size && *a)
    {
        if ((*a)->data < piv)
        {
        pb(a, b);
        moves++;
        if(((*b) != NULL) && ((*b)->next != NULL))
        {
            if ((calc = calc_dist(b)) > 1 && !((*b)->data < (*b)->tail->data))
            handle_distance(b, calc);
            else if (((*b)->data < (*b)->next->data) && ((*b)->data > (*b)->tail->data) /* && ((*b)->next->next != NULL) && ((*b)->next->next->data < (*b)->data) */)
            sb(b);
            else if (((*b)->data < (*b)->tail->data) && ((*b)->next != NULL))
            rb(b);
            print_list(*a);
	print_list(*b);
        }
        }
        else
        { 
        rra(a);
        count++;
        }
/*         if (moves == 0)
         ft_printf("warnin\n");
        ft_printf("count:%d\n", count);
        ft_printf("size:%d\n", size);
    } */
    }
}

void try_sort(t_node **stacka, t_node **stackb, int size)
{
    int piv;
    
    if (size <= 3)
    {
    sort_three(stacka);
    return;
    }
    
    piv = find_pivot(stacka);
    party(stacka, stackb, piv);

    ft_printf("before:\n");
    print_list(*stacka);
	print_list(*stackb);
    
    if (stack_len(*stacka) > 3)
    try_sort(stacka, stackb, stack_len(*stacka));
    if (stack_len(*stacka) == 3)
    sort_three(stacka);

    while (*stackb)
    {
    if ((*stacka)->data > (*stacka)->next->data)
    sa(stacka);     
    else if ((*stackb)->next != NULL && (*stackb)->data < (*stackb)->next->data)
    sb(stackb);
/*     else if ((*stacka)->data >= (*stackb)->data + 2)
    {
        if ((*stacka)->tail->data > (*stacka)->data)
        rrb(stackb);
        else if()
        if
    } */
    else
    pa(stackb, stacka);
    ft_printf("after:\n");
    print_list(*stacka);
	print_list(*stackb);
    }
    if ((*stacka)->data > (*stacka)->next->data)
    sa(stacka);
}
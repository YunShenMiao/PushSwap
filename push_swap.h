/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:23:10 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/10 12:25:18 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
	int			data;
	struct node	*prev;
	struct node	*next;
	struct node *tail;
}				t_node;

// int				cust_atoi(const char *str, int *error);
// node			*create_node(int data);
// int 			insert_end(t_node **head, int data);
// int				check_doubles(t_node **stacka);
int				handle_input(int argc, char *argv[], t_node **stacka);
void            try_sort(t_node **a, t_node **b);
int 			stack_len(t_node *stacka);
int				list_sorted(t_node **stack);
// swap
void			sa(t_node **node1);
void			sb(t_node **node1);
void			ss(t_node **node1, t_node **node2);
// rotate
void			ra(t_node **node1);
void			rb(t_node **node1);
void			rr(t_node **node1, t_node **node2);
// reverse rotate
void			rra(t_node **node1);
void			rrb(t_node **node1);
void			rrr(t_node **node1, t_node **node2);
// push
void			pa(t_node **topush, t_node **dest);
void			pb(t_node **topush, t_node **dest);
int				simplify_data(t_node **stacka, int stacklen);
// void			sorting_thingy(t_node **stacka);
// void			sort_three(t_node **stacka);
// int				list_sorted(t_node **stacka);
// void			free_nodes(t_node **head);

#endif
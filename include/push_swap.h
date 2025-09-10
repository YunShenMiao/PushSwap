/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:23:10 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/19 17:33:48 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
	int			data;
	struct node	*prev;
	struct node	*next;
	struct node	*tail;
}				t_node;
// input checks & create list
int				handle_input(char *argv[], t_node **stacka);
int				simplify_data(t_node **stacka, int stacklen);
// sorting
void			k_sort(t_node **a, t_node **b);
// helper
int				stack_len(t_node *stacka);
int				list_sorted(t_node **stack);
void			update_tail(t_node *head, t_node *new_tail);
int				r_sqrt(t_node **a);
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

#endif
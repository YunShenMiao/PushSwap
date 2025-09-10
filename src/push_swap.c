/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:28:35 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/24 12:21:52 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	ft_printf("Doubly Linked List: ");
	while (current != NULL)
	{
		ft_printf("%d ", current->data);
		current = current->next;
	}
	ft_printf("\n");
} */

void	free_nodes(t_node **head)
{
	t_node	*temp;

	while (*head != NULL)
	{
		temp = (*head);
		*head = (*head)->next;
		free(temp);
	}
}

void	sort_three(t_node **stacka)
{
	int	a;
	int	b;
	int	c;

	while (1)
	{
		a = (*stacka)->data;
		b = (*stacka)->next->data;
		c = (*stacka)->next->next->data;
		if ((c > a && a > b) || (a > b && b > c) || (b > c && c > a))
			sa(stacka);
		else if (b < c && c < a)
			ra(stacka);
		else if (c < a && a < b)
			rra(stacka);
		if (list_sorted(stacka) == 1)
			break ;
	}
}

void	sort_six(t_node **a, t_node **b)
{
	int	len;

	len = stack_len(*a);
	while (stack_len(*a) > 3)
	{
		if ((*a)->data == 0 || (*a)->data == len - 1 || (*a)->data == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while ((*b) != NULL)
	{
		pa(b, a);
		if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->tail->data)
			ra(a);
		else if ((*a)->data > (*a)->next->data)
			sa(a);
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stacka;
	t_node	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		return (1);
	if (handle_input(argv, &stacka) == -1)
		return (ft_printf("Error\n"), free_nodes(&stacka), 1);
	if (list_sorted(&stacka) == 1)
		return ((free_nodes(&stacka)), 0);
	if (simplify_data(&stacka, stack_len(stacka)) == -1)
		return ((ft_printf("Error\n")), (free_nodes(&stacka)), 1);
	if ((stack_len(stacka) == 2) && (stacka->data > stacka->next->data))
		sa(&stacka);
	else if (stack_len(stacka) == 3)
		sort_three(&stacka);
	else if (stack_len(stacka) <= 6)
		sort_six(&stacka, &stackb);
	else
		k_sort(&stacka, &stackb);
	free_nodes(&stacka);
	return (0);
}

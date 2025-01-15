/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:28:35 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/13 14:54:51 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int choose_pivot(t_node **stacka)
{
	node	*temp;
	int		count;
	int		arr[5];
	node	*temp;

	temp = (*stacka);
	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
} */

void	free_nodes(t_node **head)
{
	t_node *temp;
	
	while (*head != NULL)
	{
		temp = (*head);
		*head = (*head)->next;
		free(temp);
	}
}

void	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	printf("Doubly Linked List: ");
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
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
		break;
		temp = temp->next;
	}
	if (temp->next == NULL)
		return (1);
	temp = (*stack);
		while ((temp->next != NULL))
	{
		if (temp->data < temp->next->data)
		break;
		temp = temp->next;
	}
	if (temp->next == NULL)
			return (-1);
	return (0);
}

/* void	sort_three(t_node **stacka)
{
	node	*temp;
	node	*temp2;

	while (1)
	{
		temp = (*stacka);
		temp2 = (*stacka)->next;
		if (temp2->next->data > temp->data && temp->data > temp2->data
			|| temp->data > temp2->data && temp2->data > temp2->next->data
			|| temp2->data > temp2->next->data
			&& temp2->next->data > temp->data)
			sa(stacka);
		else if (temp2->data < temp2->next->data
			&& temp2->next->data < temp->data)
			ra(stacka);
		else if (temp2->next->data < temp->data && temp->data < temp2->data)
			rra(stacka);
		if (list_sorted(stacka) == 1)
			break ;
	}
} */

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

/* int stack_len(t_node *stacka)
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
} */

/* void create_two(t_node **stacka, t_node **stackb, int stacklen)
{
	int pivot;
	t_node *tempa;

	pivot = pivot = find_pivot(stacklen);
	while(stack_len((*stacka)) > pivot)
	{
	tempa = (*stacka);
	if (tempa->data > pivot)
	ra(stacka);
	else
	pb(stacka, stackb);
	}
} */

int	main(int argc, char *argv[])
{
	t_node	*stacka;
	t_node	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (handle_input(argc, argv, &stacka) == -1)
		return (printf("Error\n"), free_nodes(&stacka), 1);
	if (list_sorted(&stacka) == 1)
		return (printf("sorted\n"), (free_nodes(&stacka)), 0);
	if ((stack_len(stacka) == 2) && (stacka->data > stacka->next->data))
		sa(&stacka);
	else if(stack_len(stacka) == 3)
	sort_three(&stacka);
 	else
	{
	if (simplify_data(&stacka, stack_len(stacka)) == -1)
	return((ft_printf("Error\n")), (free_nodes(&stacka)), 1);
	try_sort(&stacka, &stackb);
	}
	print_list(stacka);
	print_list(stackb);
	free_nodes(&stacka);
	return (0);
}

// normalise data 
// then i know median & do quick sort maybe?
// do research on algorithms
// turk / quick sort / k sort
// goal: use least instructions possible
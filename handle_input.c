/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:24:43 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/18 15:26:52 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cust_atoi(const char *str, int *error)
{
	int		count;
	int		sign;
	long	res;

	count = 0;
	sign = 1;
	res = 0;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		res = res * 10 + (str[count] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
			return ((*error = -1), 0);
		count++;
	}
	if ((str[count] > '9' || str[count] < '0') && str[count] != '\0')
		return ((*error = -1), 0);
	return (sign * res);
}

t_node	*create_node(int data)
{
	t_node *newnode;
    
    newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->tail = newnode;
	return (newnode);
}

void update_tail(t_node *head, t_node *new_tail)
{
	t_node *temp;

	temp = head;
	while (temp)
	{
		temp->tail = new_tail;
		temp = temp->next;
	}
}

int	insert_end(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = create_node(data);
	if (!new_node)
		return (-1);
	if ((*head) == NULL)
	{
		*head = new_node;
		return(1);
	}
	else
	{
		temp = (*head);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	new_node->next = NULL;
	update_tail(*head, new_node);
	return(1);
}

int check_doubles(t_node **head)
{
	t_node *temp1;
	t_node *temp2;

	temp1 = (*head);
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->data == temp2->data)
			return(-1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
return(1);
}

int	handle_input(int argc, char *argv[], t_node **stacka)
{
	int	i;
	int	data;
	int	error;

	i = 1;
	data = 0;
	error = 0;
	if (argc < 2)
		return (-1);
	else
	{
		while (argv[i] != NULL)
		{
			data = cust_atoi(argv[i], &error);
			if (error == -1)
				return (-1);
			if (insert_end(stacka, data) == -1)
			return(-1);
			i++;
		}
	}
 	if (check_doubles(stacka) == -1)
		return (-1);
	return (1);
}

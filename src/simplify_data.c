/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:38:51 by jwardeng          #+#    #+#             */
/*   Updated: 2025/01/18 19:59:44 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_array(int **datarr, int stacklen)
{
	int	s;
	int	i;
	int	t;

	s = 0;
	while (s < stacklen - 1)
	{
		i = 0;
		while (i < stacklen - s - 1)
		{
			if ((*datarr)[i] > (*datarr)[i + 1])
			{
				t = (*datarr)[i + 1];
				(*datarr)[i + 1] = (*datarr)[i];
				(*datarr)[i] = t;
			}
			i++;
		}
		s++;
	}
}

void	datarray(t_node **stacka, int stacklen, int **datarr)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = (*stacka);
	while (i < stacklen)
	{
		(*datarr)[i] = temp->data;
		temp = temp->next;
		i++;
	}
	sort_array(datarr, stacklen);
}

int	simplify_data(t_node **stacka, int stacklen)
{
	int		*datarr;
	t_node	*temp;
	int		i;

	datarr = malloc(stacklen * sizeof(int));
	if (!datarr)
		return (-1);
	temp = (*stacka);
	datarray(stacka, stacklen, &datarr);
	while (temp != NULL)
	{
		i = 0;
		while (i < stacklen)
		{
			if (temp->data == datarr[i])
			{
				(temp)->data = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
	free(datarr);
	return (0);
}

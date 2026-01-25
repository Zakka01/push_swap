/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indxing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:05:56 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/17 23:54:23 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_all_nodes(t_list **a_stack)
{
	t_list	*current;

	current = *a_stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
}

int	find_min(t_list **a_stack)
{
	t_list	*current;
	int		min;
	int		pos_min;
	int		i;
	int		found;

	current = *a_stack;
	i = 0;
	found = 0;
	while (current)
	{
		if (current->index == -1)
		{
			if (!found || current->data < min)
			{
				min = current->data;
				pos_min = i;
				found = 1;
			}
		}
		current = current->next;
		i++;
	}
	return (pos_min);
}

void	index_nodes(t_list **a_stack, int size)
{
	t_list	*current;
	int		idx;
	int		i;
	int		pos_min;

	initial_all_nodes(a_stack);
	idx = 0;
	pos_min = 0;
	while (idx <= size - 1)
	{
		i = 0;
		pos_min = find_min(a_stack);
		current = *a_stack;
		while (i <= pos_min)
		{
			if (i == pos_min)
			{
				current->index = idx;
				break ;
			}
			current = current->next;
			i++;
		}
		idx++;
	}
}

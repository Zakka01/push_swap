/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:16:50 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/18 00:12:31 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_list **a_stack)
{
	t_list	*current;
	int		is_sorted;

	is_sorted = 1;
	current = *a_stack;
	while (current->next)
	{
		if (current->data > current->next->data)
			is_sorted = -1;
		current = current->next;
	}
	if (is_sorted == -1)
		return (0);
	return (1);
}

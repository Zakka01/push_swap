/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:48:38 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/17 21:51:54 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **h_stack, char w_stack)
{
	t_list	*current;
	t_list	*prev;

	if (!h_stack || !*h_stack || !(*h_stack)->next)
		return ;
	current = *h_stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	add_to_front(h_stack, current);
	if (w_stack == 'a')
		write(1, "rra\n", 4);
	if (w_stack == 'b')
		write(1, "rrb\n", 4);
}

void	rev_rotate_both(t_list **a_stack, t_list **b_stack)
{
	rev_rotate(a_stack, 'a');
	rev_rotate(b_stack, 'b');
	write(1, "rrr\n", 4);
}

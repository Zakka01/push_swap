/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:03:43 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/17 23:53:56 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **h_stack, char w_stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *h_stack;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*h_stack = second;
	if (w_stack == 'a')
		write(1, "sa\n", 3);
	if (w_stack == 'b')
		write(1, "sb\n", 3);
}

void	swap_both(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack, 'a');
	swap(b_stack, 'b');
	write(1, "ss\n", 3);
}

void	push(t_list **src_stack, t_list **dst_stack, char w_stack)
{
	t_list	*src_head;
	t_list	*dst_head;

	if (!src_stack || !*src_stack)
		return ;
	src_head = *src_stack;
	dst_head = *dst_stack;
	*src_stack = src_head->next;
	src_head->next = dst_head;
	*dst_stack = src_head;
	if (w_stack == 'a')
		write(1, "pa\n", 3);
	if (w_stack == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_list **h_stack, char w_stack)
{
	t_list	*head;

	if (!h_stack || !*h_stack || !(*h_stack)->next)
		return ;
	head = *h_stack;
	*h_stack = head->next;
	head->next = NULL;
	add_to_back(h_stack, head);
	if (w_stack == 'a')
		write(1, "ra\n", 3);
	if (w_stack == 'b')
		write(1, "rb\n", 3);
}

void	rotate_both(t_list **a_stack, t_list **b_stack)
{
	rotate(a_stack, 'a');
	rotate(b_stack, 'b');
	write(1, "rr\n", 3);
}

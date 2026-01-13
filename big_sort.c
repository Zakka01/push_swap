/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:06:59 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/12 22:10:31 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max_pos(n_list **b_stack)
{
    n_list *current;
    int i;
    int max_index;
    int max_pos;

    if (!b_stack || !*b_stack)
        return (-1);
    current = *b_stack;
    max_index = current->index;
    i = 0;
    max_pos = 0;
    while (current)
    {
        if (current->index > max_index)
        {   
            max_index = current->index;
            max_pos = i;
        }
        i++;
        current = current->next;
    }
    return (max_pos);
}

void push_max_to_a(n_list **a_stack, n_list **b_stack)
{
    int max_pos;
    int b_size;
    int times;

    while (*b_stack)
    {
        b_size = list_size(*b_stack);
        max_pos = find_max_pos(b_stack);
        if (max_pos == -1)
            break;
        if (max_pos <= b_size / 2)
        {
            while (max_pos > 0)
            {
                rotate(b_stack, 'b');
                max_pos--;
            }
        }
        else
        {
            times = b_size - max_pos;
            while (times > 0)
            {
                rev_rotate(b_stack, 'b');
                times--;
            }
        }
        push(b_stack, a_stack, 'a');
    }
}

void chunks_sort(n_list **a_stack, n_list **b_stack, int size)
{
    int low;
    int high;
    int index;

    index_nodes(a_stack, size);
    low = 0;
    high = size * 0.05 + 10;
    while (*a_stack)
    {
        index = (*a_stack)->index;
        if (index < low)
        {
            push(a_stack, b_stack, 'b');
            rotate(b_stack, 'b');
            low++;
            high++;
        }
        else if (index >= low && index < high)
        {
            push(a_stack, b_stack, 'b');
            low++;
            if (high < size)
                high++;
        }
        else if (index >= high)
            rotate(a_stack, 'a');
    }
    push_max_to_a(a_stack, b_stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:06:59 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/12 00:00:49 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    get_chunk_size(n_list **a_stack, int size)
{
    int chunk_size;
    
    if (size <= 100)
        chunk_size = 15;
    else
        chunk_size = 35;
    return (chunk_size);
}

void    chunks_sort(n_list **a_stack, n_list **b_stack, int size)
{
    n_list  *current;
    int low;
    int high;
    int index;
    
    index_nodes(a_stack, size); // node are indexed now !
    current = *a_stack;
    low = 0;
    high = get_chunk_size(a_stack, size);
    while (current)
    {
        index = current->index;
        if (index < low) // we are already handled this chunk | push to B then rotate 
        {
            push(a_stack, b_stack, 'b');
            rotate(b_stack, 'b');
        }
        else if (index >= low && index < high) // this belongs to the current chunk | push to B 
        {
            push(a_stack, b_stack, 'b');
            low++;
            high++;
        }
        else if (index >= high) // does not belong to the current chunk | skip for now - rotate 
            rotate(a_stack, 'a');
        current = current->next;
    }
}

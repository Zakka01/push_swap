/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indxing_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:05:56 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/08 20:42:58 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initial_all_nodes(n_list **a_stack)
{
    n_list *current;

    current = *a_stack;
    while (current)
    {
        current->index = -1;
        current = current->next;
    }
}

int init_min(n_list **a_stack)
{
    n_list *current;
    int min;

    min = 0;
    current = *a_stack;
    while (current)
    {
        if (current->index == -1)
        {
            min = current->data;
            break;
        }
        current = current->next;
    }
    return (min);
}

int find_min(n_list **a_stack)
{
    n_list *current;
    int pos_min;
    int i;
    int min;

    current = *a_stack;
    i = 0;
    min = init_min(a_stack);
    while (current)
    {
        if (min >= current->data && current->index == -1)
        {
            min = current->data;
            pos_min = i;
        }
        current = current->next;
        i++;
    }
    return (pos_min);
}


void index_nodes(n_list **a_stack, int size)
{
    n_list *current;
    int idx;
    int i;
    int pos_min;

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
                current->index = idx;
            current = current->next;
            i++;
        }
        idx++;
    }
}

void chunks_algo(n_list **a_stack, n_list **b_stack)
{
    n_list *current;
    int size;
    int idx;
    int pos;
    int i;
    int times;

    size = list_size(*a_stack);
    index_nodes(a_stack, size);

    idx = 0;
    while (*a_stack != NULL)
    {
        i = 0;
        current = *a_stack;
        while (current)
        {
            if (current->index == idx)
            {
                pos = i;
                break;
            }
            i++;
            current = current->next;
        }
        size = list_size(*a_stack);
        if (pos == 0)
            push(a_stack, b_stack, 'b');
        else if (pos < size / 2)
        {
            while (pos > 0)
            {
                rotate(a_stack, 'a');
                pos--;
            }
            push(a_stack, b_stack, 'b');
        }
        else
        {
            times = size - pos;
            while (times > 0)
            {
                rev_rotate(a_stack, 'a');
                times--;
            }
            push(a_stack, b_stack, 'b');
        }
        if (*a_stack == NULL)
            break;
        idx++;
    }

    while (*b_stack)
    {
        push(b_stack, a_stack, 'a');
    }
}

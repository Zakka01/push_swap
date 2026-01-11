/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:06:06 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/12 00:00:25 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// add new node
n_list *add_new_node(int content)
{
    n_list *new_node;

    new_node = malloc(sizeof(n_list));
    if (!new_node)
        return (NULL);
    new_node->data = content;
    if (new_node)
        new_node->next = NULL;
    return (new_node);
}

// add a node to the end of a list
void add_to_back(n_list **list, n_list *node)
{
    n_list *tmp;

    if (!*list)
    {
        *list = node;
        return;
    }

    tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}

// add a node to the front
void add_to_front(n_list **list, n_list *node)
{
    if (!list || !node)
        return;
    node->next = *list;
    *list = node;
}

// this fuction count the size of a linked-list
int list_size(n_list *list)
{
    int size;

    size = 0;

    while (list)
    {
        size++;
        list = list->next;
    }
    return (size);
}

// parsing the input and create a list contains node with its data
int    parse_create_list(char *arg, n_list **a_head)
{
    int     j;
    int     number;
    char    **numbers;
    n_list  *node;
    int     error;
    
    numbers = ft_split(arg);
    if (!numbers)
        return (0);
    j = 0;
    while (numbers[j])
    {
        number = ft_atoi(numbers[j], &error);
        if (error == -1)
            return (0);
        node = add_new_node(number);
        add_to_back(a_head, node);
        j++;
    }
    free_all_space(numbers, j);
    return (1);
}

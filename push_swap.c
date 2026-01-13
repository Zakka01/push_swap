/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:06:02 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/13 17:44:02 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>

void	check_leaks(void)
{
	system("leaks push_swap");
}


int main(int ac, char **av)
{
    int i;
    n_list *a_head;
    n_list *b_head;

    a_head = NULL;
    b_head = NULL;
    if (ac >= 2)
    {
        i = 1;
        while (ac > i)
        {
            if (!parse_create_list(av[i], &a_head))
                return (write(1, "Error\n", 6), 0);
            i++;
        }
        if (!check_dup(a_head))
            return (write(1, "Error\n", 6), 0);
        handle_list_size(&a_head, &b_head);
    }
    atexit(check_leaks);
}

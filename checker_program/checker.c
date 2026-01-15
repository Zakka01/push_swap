/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:12:09 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/15 20:03:08 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(n_list **stack)
{
    n_list *current;
	n_list *tmp;

    current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

void apply_valid_move(char *line, n_list **a_stack, n_list **b_stack)
{
    if (validate_line(line))
    {
        if (is_move(line, "sa"))
            swap(a_stack);
        else if (is_move(line, "sb"))
            swap(b_stack);
        else if (is_move(line, "ss"))
            swap_both(a_stack, b_stack);
        else if (is_move(line, "ra"))
            rotate(a_stack);
        else if (is_move(line, "rb"))
            rotate(b_stack);
        else if (is_move(line, "rr"))
            rotate_both(a_stack, b_stack);
        else if (is_move(line, "pa"))
            push(b_stack, a_stack);
        else if (is_move(line, "pb"))
            push(a_stack, b_stack);
        else if (is_move(line, "rra"))
            rev_rotate(a_stack);
        else if (is_move(line, "rrb"))
            rev_rotate(b_stack);
        else if (is_move(line, "rrr"))
            rev_rotate_both(a_stack, b_stack);
    }
}

void    check_ok(n_list **a_stack)
{
    if (is_sorted(a_stack))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}

int main(int ac, char **av)
{
    int     i;
    n_list  *a_head;
    n_list  *b_head;
    char    *line;

    a_head = NULL;
    b_head = NULL;
    if (ac >= 2)
    {
        i = 1;
        while (ac > i)
        {
            if (!parse_create_list(av[i], &a_head))
                return (write(1, "Error\n", 6), free_stack(&a_head), 0);
            i++;
        }
        if (!check_dup(a_head))
            return (write(1, "Error\n", 6), free_stack(&a_head), 0);
    }
    while ((line = get_line(0)))
{
    if (!validate_line(line))
    {
        write(2, "Error\n", 6);
        free(line);
        free_stack(&a_head);
        free_stack(&b_head);
        return 1;
    }
    apply_valid_move(line, &a_head, &b_head);
    free(line);
}

    check_ok(&a_head);
    free_stack(&a_head);
    free_stack(&b_head);
    return (0);
}

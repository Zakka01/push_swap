/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:46:44 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/15 18:26:00 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int is_move(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (0);
        i++;
    }
    return (1);
}

int validate_line(char *line)
{
    if ((is_move(line, "sa")) || (is_move(line, "sb")) || (is_move(line, "ss")))
        return (1);
    else if ((is_move(line, "pa")) || (is_move(line, "pb")))
        return (1);
    else if ((is_move(line, "ra")) || (is_move(line, "rb")) || (is_move(line, "rr")))
        return (1);
    else if ((is_move(line, "rra")) || (is_move(line, "rrb")) || (is_move(line, "rrr")))
        return (1);
    else 
        return (0);
}
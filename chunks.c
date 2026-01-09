/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:06:59 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/09 18:14:23 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    get_chunks(n_list   **a_stack, n_list **b_stack, int size)
{
    int chunks;
    
    if (size > 10 && size <= 50)
        chunks = 2;
    else if (size > 50 && size <= 100)
        chunks = 5;
    else if (size > 100 && size <= 500)
        chunks = 11;
    
}
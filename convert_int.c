/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zahrabar <zahrabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:03:37 by zahrabar          #+#    #+#             */
/*   Updated: 2026/01/06 23:44:16 by zahrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

// handle the overflow - if the res exceeded the range
static int ov_check(unsigned long res, int digit, int sign)
{
    if (sign == 1)
    {
        if (res > (unsigned long)(INT_MAX - digit) / 10)
            return (0);
    }
    else
    {
        if (res > ((unsigned long)INT_MAX + 1 - digit) / 10)
            return (0);
    }
    return (1);
}

// The main function that Mimic the libc atoi
int	ft_atoi(char	*str, int *error)
{
	int				i;
	unsigned long	res;
	int				sign;
	int				digit;

	i = 0;
	res = 0;
	sign = 1;
	if (((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1])) || ft_isdigit(str[i]))
	{
		if (str[i++] == '-')
			sign = -1;
	}
	else
		*error = -1;
	while (str[i++])	
	{
		if (!ft_isdigit(str[i]))
			*error = -1;
		digit = str[i] - '0';
		if (!ov_check(res, digit, sign))
			*error = -1;
		res = res * 10 + digit;
	}
	return ((res * sign));
}

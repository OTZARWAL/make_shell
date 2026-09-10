/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:41:28 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/02 11:57:37 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_spaces(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					q;
	int					i;

	i = 0;
	res = 0;
	q = 1;
	while (ft_skip_spaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			q *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 9223372036854775807 && q == 1)
			return (-1);
		if (res > 9223372036854775807 && q == -1)
			return (0);
		res = res * 10 + (str[i++] - '0');
	}
	return (res *= q);
}
// #include <stdio.h>
// int main(void)
// {
//     char str[] = " 922337203685475575809";
//     printf("%d\n", ft_atoi(str));
//     printf("%d\n", atoi(str));
//     return (0);
// }

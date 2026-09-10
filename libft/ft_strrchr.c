/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:23:06 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/02 10:57:27 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*p;
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(str);
	p = (NULL);
	while (i <= len)
	{
		if ((char)*str == (char)c)
			p = str;
		str++;
		i++;
	}
	return ((char *)p);
}

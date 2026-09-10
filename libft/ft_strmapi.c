/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:37:55 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/02 10:57:14 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buff;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	buff = (char *)malloc(s_len + 1);
	if (!buff)
		return (NULL);
	while (i < s_len)
	{
		buff[i] = f(i, s[i]);
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

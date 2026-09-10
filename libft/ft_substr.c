/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:35:47 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/02 10:57:33 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	buff = malloc(len + 1);
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, s + start, len + 1);
	return (buff);
}

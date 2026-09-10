/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:20:46 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/02 10:56:06 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p;

	p = dst;
	i = len;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (i-- > 0)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
		ft_memcpy(dst, src, i);
	return ((void *)p);
}

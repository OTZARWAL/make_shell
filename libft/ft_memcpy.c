/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:11:14 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/10 19:56:06 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// int main()
// {
// 	char s1[20] = "otmanert";
// 	char s2[20] = "otmanert";

// 	// ft_memcpy(s1 + 2, s1, 4);
// 	ft_memcpy(s2 + 2, s2, 4);
// 	memcpy(s1 + 2, s1, 5);



// 	printf(" %s\n", s1);
// 	printf(" %s\n", s2);
// }

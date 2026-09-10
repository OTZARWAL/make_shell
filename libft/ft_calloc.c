/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:02:00 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/03 14:34:53 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buff;

	if (count != 0 && ((count * size) / count) != size)
		return (NULL);
	buff = malloc(count * size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, count * size);
	return (buff);
}

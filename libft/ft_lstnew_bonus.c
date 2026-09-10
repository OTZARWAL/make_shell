/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:39:59 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/10 19:55:40 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>


t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// int main()
// {
// 	t_list *new, *node, *node2, *header, *first, *second;
// 	new = ft_lstnew("mouad");

// 	node = ft_lstnew("ayoub");

// 	node2 = ft_lstnew("otmane");

// 	header = NULL;

// 	new->next = node;
// 	node->next = node2;
// 	if (header == NULL)
// 		header = new;
// 	else
// 		header->next = new;

// 	first = header;
// 	second = header;
// 	while(second)
// 	{
// 		printf("%s\n", second->content);
// 		second = second->next;
// 	}
// 	while(first)
// 	{
// 		printf("%s\n", first->content);
// 		first = first->next;
// 	}

// }



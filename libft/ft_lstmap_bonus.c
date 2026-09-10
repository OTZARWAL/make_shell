/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otzarwal <otzarwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:06:04 by otzarwal          #+#    #+#             */
/*   Updated: 2024/11/03 14:41:49 by otzarwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void *edit(void *content)
// {
//     int i = 0;
//     char *s = content;
//     while(s[i])
//     {
//         if (s[i] >= 'a' && s[i] <= 'z')
//         {
//            s[i] -=  32;
//         }
//          i++;
//     }
//     return (content);
// }

// void    put_list(t_list *node)
// {
//     if (!node)
//         return ;
//     while (node)
//     {
//         printf("%s\n", (char *)node->content);
//         node = node->next;
//     }
// }

// void del_node(void *content)
// {
//     free(content);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;
	void	*s;

	newlist = NULL;
	if (!f || !del)
		return (newlist);
	while (lst)
	{
		s = f(lst->content);
		node = ft_lstnew(s);
		if (!node)
		{
			del(s);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, node);
		lst = lst->next;
	}
	return (newlist);
}

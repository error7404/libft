/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:40:49 by jcollon           #+#    #+#             */
/*   Updated: 2022/01/18 19:55:34 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the content
 * of each node. Creates a new list resulting of the successive applications of
 * the function 'f'. The 'del' function is used to delete
 * the content of a node if needed.
 * 
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of
 * a node if needed.
 * @return t_list* The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		ft_lstclear(&lst, del);
	if (!temp)
		return (0);
	ret = temp;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&ret, del);
			return (0);
		}
		ft_lstadd_back(&ret, temp);
		lst = lst->next;
	}
	return (ret);
}

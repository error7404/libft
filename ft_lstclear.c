/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:22:59 by jcollon           #+#    #+#             */
/*   Updated: 2022/01/18 19:51:45 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free. Finally, the pointer to the list
 * is set to NULL.
 * 
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		del(tmp2->content);
		free(tmp2);
	}
	*lst = 0;
}

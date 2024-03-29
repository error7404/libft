/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:22:59 by jcollon           #+#    #+#             */
/*   Updated: 2023/10/19 17:37:54 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		del(tmp2->content);
		free(tmp2);
	}
	*lst = 0;
}

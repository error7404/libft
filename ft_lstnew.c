/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:33:01 by jcollon           #+#    #+#             */
/*   Updated: 2022/01/18 19:42:42 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a new t_list
 * 
 * @param content The content to create the node with
 * @return t_list* The new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = malloc(sizeof(*ret));
	if (!ret)
		return (0);
	ret->content = content;
	ret->next = 0;
	return (ret);
}

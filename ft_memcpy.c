/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:06:46 by jcollon           #+#    #+#             */
/*   Updated: 2021/11/03 10:06:46 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;

	if (!dest && !src)
		return (0);
	d = dest;
	while (n)
	{
		*d = *(char *) src;
		d++;
		src++;
		n--;
	}
	return (dest);
}

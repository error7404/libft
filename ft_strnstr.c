/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:59:47 by jcollon           #+#    #+#             */
/*   Updated: 2021/11/10 04:39:52 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (*needle == 0)
		return ((char *) haystack);
	while (len && *haystack)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (len - i && haystack[i] == needle[i]
				&& haystack[i] && needle[i])
				i++;
			if (i == ft_strlen(needle))
				return ((char *) haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}

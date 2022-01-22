/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:54:34 by jcollon           #+#    #+#             */
/*   Updated: 2021/11/15 15:22:21 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	size_t			len_malloc;

	if (!s)
		return (0);
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	len_malloc = ft_strlen(s + start);
	if (len_malloc >= len)
		len_malloc = len;
	ret = malloc((len_malloc + 1) * sizeof(*ret));
	if (!ret)
		return (0);
	i = 0;
	while (len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
		len--;
	}
	ret[i] = 0;
	return (ret);
}

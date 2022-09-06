/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:15:19 by jcollon           #+#    #+#             */
/*   Updated: 2022/09/06 14:41:04 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int j)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((j + 1) * sizeof(*dst));
	if (!dst)
		return (0);
	while (i < j && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_len_word(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			i += ft_len_word(&str[i], c);
		}
	}
	return (count + 1);
}

static char	**cleartab_init(char **ret, int max)
{
	int	i;

	if (!ret)
	{
		ret = malloc(sizeof(*ret) * max);
		if (!ret)
			return (0);
		return (ret);
	}
	i = 0;
	while (i <= max)
		free(ret[i]);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		word;
	int		max_word;
	int		i;

	if (!s)
		return (0);
	word = -1;
	max_word = ft_count_words(s, c);
	i = 0;
	ret = cleartab_init(0, max_word);
	while (++word < max_word - 1)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			ret[word] = ft_strndup(&s[i], ft_len_word(&s[i], c));
			if (!ret[word])
				return (cleartab_init(ret, word - 1));
			i += ft_len_word(&s[i], c);
		}
	}
	ret[word] = 0;
	return (ret);
}

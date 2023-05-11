/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccossell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:43 by ccossell          #+#    #+#             */
/*   Updated: 2023/04/20 19:19:35 by ccossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	substr = (char *) malloc(sizeof(*s) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			substr[j++] = s[i];
		i++;
	}
	substr[j] = 0;
	return (substr);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (! *s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**shortcut(char const *s, char **first, char c, size_t wordlen)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				wordlen = ft_strlen(s);
			else
				wordlen = ft_strchr(s, c) - s;
			first[i++] = ft_substr1(s, 0, wordlen);
			s += wordlen;
		}
	}
	first[i] = NULL;
	return (first);
}

char	**ft_split(char const *s, char c)
{
	char	**first;
	size_t	wordlen;

	wordlen = 0;
	if (!s)
		return (NULL);
	first = (char **)malloc((ft_countword(s, c) + 1) * sizeof (char *));
	if (!first)
		return (0);
	first = shortcut(s, first, c, wordlen);
	return (first);
}

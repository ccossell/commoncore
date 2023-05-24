/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:16:47 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 17:19:09 by ccossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*strm;

	if (!str)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	strm = (char *)malloc(ft_strlen(str) + ft_strlen(buff) + 1);
	if (strm == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i] != '\0')
			strm[i] = str[i];
	while (buff[j] != '\0')
		strm[i++] = buff[j++];
	strm[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (strm);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*strm;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	strm = (char *)malloc(i + 2);
	if (!strm)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		strm[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		strm[i] = str[i];
		i++;
	}
	strm[i] = '\0';
	return (strm);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*strm;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	strm = (char *)malloc(ft_strlen(str) - i + 1);
	if (!strm)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		strm[j++] = str[i++];
	strm[j] = '\0';
	free(str);
	return (strm);
}

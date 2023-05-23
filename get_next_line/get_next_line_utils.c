/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:16:47 by marvin            #+#    #+#             */
/*   Updated: 2023/05/23 17:16:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    ft_get_line(char *str)
{
    int     i;
    char    *strm;

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

char    ft_new_str(char *str)
{
    int     i;
    int     j;
    char    *strm;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str)
    {
        free(str);
        return (NULL);
    }
    strm = (char *)malloc(ft_strlen(str) - i + 1);
    if (!strm)
        return (NULL);
    i++;
    j = 0;
    while (str[j])
        strm[j++] = str[i++];
    strm[j] = '\0';
    free(str);
    return (strm);
}
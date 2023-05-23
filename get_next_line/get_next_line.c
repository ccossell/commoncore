/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:51:17 by marvin            #+#    #+#             */
/*   Updated: 2023/05/23 18:51:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read_to_str(int fd, char *str)
{
    char    *buff;
    int     rd_bytes;

    buff = (char *)malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    rd_bytes = 1;
    while (!ft_strchr(str, '\n') && rd_bytes != 0)
    {
        rd_bytes = read(fd, buff, BUFFER_SIZE);
        if (rd_bytes = -1)
        {
            free(buff);
            return (NULL);
        }
        buff[rd_bytes] = '\0';
        str = ft_strjoin(str, buff);
    }
    free(buff);
    return (str);
}

char    *get_next_line(int fd)
{
    char        *line;
    static char *str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    str = ft_read_to_str(fd, str);
    if (!str)
        return (NULL);
    line = ft_get_line(str);
    str = ft_new_str (str);
    return (line);
}
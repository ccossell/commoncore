/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccossell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:42:35 by ccossell          #+#    #+#             */
/*   Updated: 2023/03/29 12:44:53 by ccossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chr;
	size_t			i;
	unsigned char	character;

	character = (unsigned char)c;
	chr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*chr == character)
			return (chr);
		chr++;
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccossell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:32:25 by ccossell          #+#    #+#             */
/*   Updated: 2023/03/29 16:13:57 by ccossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (dstsize < 1)
		return (len2 + dstsize);
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (dst[i])
		i++;
	while (*src && i < dstsize - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	if (dstsize < len1)
		return (len2 + dstsize);
	else
		return (len1 + len2);
}

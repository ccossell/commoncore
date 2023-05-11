/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccossell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:28:58 by ccossell          #+#    #+#             */
/*   Updated: 2023/04/19 17:12:49 by ccossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	i;

	i = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	min_int(int n, char *str)
{
	str [0] = '-';
	n *= -1;
	if (n == -2147483648)
	{	
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = get_digits(n);
	if (n < 0)
		digits++;
	str = (char *)malloc(digits + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		n = min_int(n, str);
	*(str + digits) = 0;
	while (n > 9)
	{
		digits--;
		*(str + digits) = n % 10 + '0';
		n /= 10;
	}
	digits--;
	*(str + digits) = n % 10 + '0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccossell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:17:33 by ccossell          #+#    #+#             */
/*   Updated: 2023/05/11 16:59:53 by ccossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_format(va_list arg, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_printchar(va_arg(arg, int));
	else if (format == '%')
		print_len += ft_print_percent();
	else if (format == 's')
		print_len += ft_printstr(va_arg(arg, char *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(arg, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += ft_printnbr(va_arg(arg, int));
	else if (format == 'u')
		print_len += ft_print_unsigned(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(arg, unsigned int), format);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		print_len;

	print_len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_format(arg, str[i + 1]);
			i++;
		}
		else
			print_len += ft_printchar(str[i]);
		i++;
	}
	va_end(arg);
	return (print_len);
}

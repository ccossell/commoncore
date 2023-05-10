/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:38:47 by marvin            #+#    #+#             */
/*   Updated: 2023/05/10 21:38:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int ft_ptr_len(uniptr_t num)
{
    int len;

    len = 0;
    while(num)
    {
        len++;
        num /= 16;
    }
    return (len);
}

void    ft_put_ptr(uinptr_t num)
{
    if (num >= 16)
    {
        ft_put_ptr(num / 16);
        ft_put_ptr(num % 16);
    }
    else
    {
        if (num <= 9)
            ft_putchar_fd((num + '0'), 1);
        else
            ft_putchar_fd((num - 10 + 'a'), 1);
    }
}

int ft_print_ptr(unsigned long long ptr)
{
    int print_len;

    print_len = 0;
    if (ptr == 0)
        print_len += write(1, "0", 1);
    else
    {
        ft_put_ptr(ptr);
        print_len += ft_ptr_len(ptr);
    }
    return (print_len);
}
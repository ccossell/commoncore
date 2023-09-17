/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccossell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:19:02 by ccossell          #+#    #+#             */
/*   Updated: 2023/09/17 17:56:05 by ccossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	char	digit;

	if (n > 9)
		ft_putnbr(n / 10);
	digit = n % 10 + 48;
	write (1, &digit, 1);
}

void	sig_handle(int signal)
{
	static int	i;
	static int	n;
	int			nb;

	if (signal == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	n = (n << 1) + nb;
	i++;
	if (i == 8)
	{
		write(1, &n, 1);
		i = 0;
		n = 0;
	}
}

int	main(void)
{
	write(1, "Benvenuto nel server di Claudio", 31);
	write(1, "\n", 1);
	write(1, "Il mio PID é:", 13);
	write(1, "\n", 1);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR2, sig_handle);
		signal(SIGUSR1, sig_handle);
		pause();
	}
	return (0);
}

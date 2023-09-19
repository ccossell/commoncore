/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:02:54 by anlima            #+#    #+#             */
/*   Updated: 2023/09/19 18:57:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(long nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
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
	struct sigaction	sigact;

	sigact.sa_handler = &sig_handle;
	sigact.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sigact, 0);
	sigaction(SIGUSR2, &sigact, 0);
	write(1, "Benvenuto nel server di Claudio", 31);
	write(1, "Il PID è", 8);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		usleep(100);
	return (0);
}

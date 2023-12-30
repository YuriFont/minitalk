/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:08:46 by yufonten          #+#    #+#             */
/*   Updated: 2023/12/30 16:59:12 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	push;

	push = 7;
	while (push >= 0)
	{
		if ((c >> push) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		push--;
		usleep(200);
	}
}


int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			send_bits(pid, av[2][i]);
			i++;
		}
	}
	else
		ft_putstr("\nWrong initialization\nTry: ./client <PID> <mensage>\n\n");
	return (0);
}

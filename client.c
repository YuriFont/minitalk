/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:08:46 by yufonten          #+#    #+#             */
/*   Updated: 2023/12/29 17:35:54 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char *str, int len)
{
	int	i;
	int	push;

	i = 0;
	while (i <= len)
	{
		push = 0;
		while (push < 8)
		{
			if ((str[i] >> push) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			push++;
			usleep(200);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_bits(pid, av[2], ft_strlen(av[2]));
	}
	else
		ft_putstr("\nWrong initialization\nTry: ./client PID Mensage\n\n", 1);
	return (0);
}

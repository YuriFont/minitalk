/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:59:14 by yufonten          #+#    #+#             */
/*   Updated: 2023/12/30 01:50:46 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_header_minitalk(void)
{
	ft_putstr("\n\n");
	ft_putstr("                      ##\n");
	ft_putstr("##  ##  ## #####  ## ##### ####  ##  ##  ##\n");
	ft_putstr("####### ## ##  ## ##  ##      ## ##  ## ##\n");
	ft_putstr("## # ## ## ##  ## ##  ##   ##### ##  ####\n");
	ft_putstr("##   ## ## ##  ## ##  ##  ##  ## ##  ## ##\n");
	ft_putstr("##   ## ## ##  ## ##  ###  ###   ### ##  ##\n\n");
}

void	getting_character(int bit)
{
	static int	i;
	static int	c;

	if (bit == SIGUSR2)
		c = (c << 1) + 1;
	else
		c = c << 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		write(1, "\n", 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_header_minitalk();
	ft_putstr("\nThis is the PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n\n");
	while (1)
	{
		signal(SIGUSR1, getting_character);
		signal(SIGUSR2, getting_character);
		pause();
	}
	return (0);
}

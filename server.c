/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:59:14 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/03 11:39:40 by yufonten         ###   ########.fr       */
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
	static int	bits;
	static char	c;

	if (bit == SIGUSR2)
	{
		c = c << 1;
		c = c | 1;
	}
	else
		c = c << 1;
	bits++;
	if (bits == 8)
	{
		ft_putchar(c);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	ft_header_minitalk();
	ft_putstr("This is the PID: ");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:59:14 by yufonten          #+#    #+#             */
/*   Updated: 2023/12/29 23:42:39 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_header_minitalk(void)
{
	ft_putstr("\n\n");
	ft_putstr("                      ##         ##  ##\n");
	ft_putstr("##  ##  ## #####  ## ##### ####  ##  ##  ##\n");
	ft_putstr("####### ## ##  ## ##  ##      ## ##  ## ##\n");
	ft_putstr("## # ## ## ##  ## ##  ##   ##### ##  ####\n");
	ft_putstr("##   ## ## ##  ## ##  ##  ##  ## ##  ## ##\n");
	ft_putstr("##   ## ## ##  ## ##  ###  ###   ### ##  ##\n\n");
}

int	main(void)
{
	ft_header_minitalk();
	ft_putstr("\nThis is the PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n\n");
	return (0);
}

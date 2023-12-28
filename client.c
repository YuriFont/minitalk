/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:08:46 by yufonten          #+#    #+#             */
/*   Updated: 2023/12/28 17:50:29 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 3)
	{
		ft_putstr("Wrong initialization\nTry: ./client PID Mensage\n", 1);
	}
	return (0);
}

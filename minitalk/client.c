/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:10:58 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/30 14:31:23 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_signal(char c, pid_t pid)
{
	int	j;

	j = 8;
	while (--j >= 0)
	{
		if (c % 2)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putendl_fd("Error while sending signal !", 2);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putendl_fd("Error while sending signal !", 2);
				exit(EXIT_FAILURE);
			}
		}
		usleep(10);
		c >>= 1;
	}
}

int	main(int argc, char *argv[])
{
	pid_t			pid;
	int				i;

	if (argc != 3)
	{
		ft_putendl_fd("Invalid argument(s) !", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
	{
		send_signal(argv[2][i], pid);
	}
	return (0);
}

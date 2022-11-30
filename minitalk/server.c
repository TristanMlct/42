/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:16:22 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/30 14:23:30 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	decode(int sig)
{
	static int		i = -1;
	static int		tab[8];
	unsigned char	c;

	if (sig == SIGUSR1)
		tab[++i] = 1;
	else if (sig == SIGUSR2)
		tab[++i] = 0;
	if (i == 7)
	{
		c = 0;
		while (i >= 0)
		{
			c <<= 1;
			c += tab[i];
			i--;
		}
		ft_putchar_fd(c, 1);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, decode);
		signal(SIGUSR2, decode);
		pause();
	}
}

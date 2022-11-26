/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:18:09 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/25 18:28:17 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isint(char *str)
{
	int			neg;
	int			i;
	long long	r;

	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	r = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += (str[i] - '0');
		i++;
	}
	r *= neg;
	if (r > 2147483647 || r < -2147483648)
		return (0);
	return (1);
}

void	free_tabstr(char *tab_str[])
{
	int	i;

	i = -1;
	while (tab_str[++i])
		free(tab_str[i]);
	free(tab_str);
}

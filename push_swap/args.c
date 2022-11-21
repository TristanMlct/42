/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:15:48 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/20 22:31:39 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		return (error());
	else if (argc == 2)
		return (check_args_as_str(argv[1]));
	else
		return (check_args_as_int(argv));
}

int	check_args_as_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
}

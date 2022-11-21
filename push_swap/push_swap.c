/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:12:36 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/22 00:05:07 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_args	*args;
	int		i;

	args = malloc(sizeof(t_args));
	args->nb = 0;
	args->tab_int = 0;
	if(check_args(args, argc, argv))
	{
		i = -1;
		while (++i < args->nb)
			ft_printf("Arg %d : %d\n", i, args->tab_int[i]);
		free(args->tab_int);
		free(args);
	}
}

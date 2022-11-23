/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:12:36 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/23 13:26:09 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_args	*args;
	t_pile	*pile_a;
	int		i;

	args = malloc(sizeof(t_args));
	args->nb = 0;
	args->tab_int = 0;
	if(check_args(args, argc, argv))
	{
		pile_a = ft_pilenew(args->tab_int[0]);
		i = 0;
		while (++i < args->nb)
			ft_pileadd_back(&pile_a, ft_pilenew(args->tab_int[i]));
		ft_pileprint(pile_a);
		ft_pileclear(&pile_a);
		free(args->tab_int);
		free(args);
	}
}

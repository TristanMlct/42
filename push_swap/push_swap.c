/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:12:36 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/26 00:58:32 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_args	*args;
	t_pile	*pile_a;
	t_pile	*pile_b;

	args = malloc(sizeof(t_args));
	args->nb = 0;
	args->tab_int = 0;
	if (check_args(args, argc, argv))
	{
		init_piles(&pile_a, &pile_b, args);
		free(args->tab_int);
		free(args);
		perform_algo(&pile_a, &pile_b);
		ft_pileclear(&pile_a);
		ft_pileclear(&pile_b);
	}
}

void	init_piles(t_pile **pile_a, t_pile **pile_b, t_args *args)
{
	int	i;

	*pile_a = 0;
	*pile_b = 0;
	i = -1;
	while (++i < args->nb)
		ft_pileadd_back(pile_a, ft_pilenew(args->tab_int[i]));
	pb(pile_a, pile_b);
	pb(pile_a, pile_b);
	pb(pile_a, pile_b);
	if ((*pile_b)->next && ((*pile_b)->next->value > (*pile_b)->value))
		sb(pile_b);
}

void	perform_algo(t_pile **pile_a, t_pile **pile_b)
{
	int	i;
	int	pos;
	int	size_pile;

	size_pile = ft_pilesize(*pile_a);
	i = -1;
	while (++i < size_pile)
	{
		ft_pileprint(*pile_a, *pile_b);
		pos = calculate_best_move(*pile_a, *pile_b);
		ft_printf("pos %d\n", pos);
		// make_best_move(pile_a, pile_b, pos);
	}
}

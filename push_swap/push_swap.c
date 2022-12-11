/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:12:36 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/11 19:24:28 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_algo(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp_pile;
	int		max;
	int		i;

	max = get_pile_max_value(*pile_b);
	tmp_pile = *pile_b;
	i = 0;
	while (tmp_pile->next && tmp_pile->value != max)
	{
		tmp_pile = tmp_pile->next;
		i++;
	}
	while (--i >= 0)
		rb(pile_b);
	max = ft_pilesize(*pile_b);
	while (++i < max)
		pa(pile_b, pile_a);
}

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
}

void	perform_algo(t_pile **pile_a, t_pile **pile_b)
{
	int	i;
	int	pos;
	int	size_pile;

	if (ft_pilesize(*pile_a) <= 3)
		small_pile_algo(pile_a);
	else if (ft_pilesize(*pile_a) <= 10)
		medium_pile_algo(pile_a, pile_b);
	else
	{
		pb(pile_a, pile_b);
		size_pile = ft_pilesize(*pile_a);
		i = -1;
		while (++i < size_pile)
		{
			pos = calculate_best_move(*pile_a, *pile_b);
			make_best_move(pile_a, pile_b, pos);
		}
		finish_algo(pile_a, pile_b);
	}
}

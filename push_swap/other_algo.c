/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:51:56 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/11 21:22:42 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_pile_algo(t_pile **pile_a)
{
	if (ft_pilesize(*pile_a) == 1)
		return ;
	else if (ft_pilesize(*pile_a) == 2)
	{
		if (!is_sorted(*pile_a))
			sa(pile_a);
	}
	else
	{
		if (get_pile_max_value(*pile_a) == (*pile_a)->value)
			ra(pile_a);
		if (get_pile_max_value(*pile_a) == (*pile_a)->next->value)
			rra(pile_a);
		if (is_sorted(*pile_a))
			return ;
		sa(pile_a);
	}
}

void	medium_pile_algo(t_pile **pile_a, t_pile **pile_b)
{
	int	i;
	int	size_pile;
	int	pos;

	size_pile = ft_pilesize(*pile_a);
	pb(pile_a, pile_b);
	i = 0;
	while (++i < size_pile - 3)
	{
		pos = calculate_best_move(*pile_a, *pile_b);
		make_best_move(pile_a, pile_b, pos);
	}
	small_pile_algo(pile_a);
	while (--i >= 0)
	{
		pos = calculate_best_move_medium(*pile_a, *pile_b);
		make_best_move_medium(pile_a, pile_b, pos);
	}
	while (!is_sorted(*pile_a))
		ra(pile_a);
}

int	calculate_best_move_medium(t_pile *pile_a, t_pile *pile_b)
{
	int	min_moves;
	int	curr_moves;
	int	i;
	int	pos;
	int	tmp;

	min_moves = -1;
	i = 0;
	while (pile_b)
	{
		curr_moves = i;
		tmp = get_nbr_move_to_be_sort_medium(pile_b->value, pile_a);
		if (tmp > ft_pilesize(pile_a) / 2)
			tmp = ft_pilesize(pile_a) - tmp;
		curr_moves += tmp;
		if (curr_moves < min_moves || min_moves == -1)
		{
			min_moves = curr_moves;
			pos = i;
		}
		i++;
		pile_b = pile_b->next;
	}
	return (pos);
}

int	get_nbr_move_to_be_sort_medium(int v, t_pile *a)
{
	int		moves;
	int		min;
	int		max;

	min = get_pile_min_value(a);
	max = get_pile_max_value(a);
	moves = 0;
	while (a->next)
	{
		if ((v < min && min == a->value)
			|| (v < a->value && v > ft_pilelast(a)->value)
			|| (v > max && ft_pilelast(a)->value == max))
			break ;
		moves++;
		if (v > max && a->value == max)
			break ;
		if (v > a->value && v < a->next->value)
			break ;
		a = a->next;
	}
	return (moves);
}

void	make_best_move_medium(t_pile **pile_a, t_pile **pile_b, int pos)
{
	int	pos_in_a_pile;
	int	size_a_pile;
	int	i;
	int	rev;

	while (--pos >= 0)
		ra(pile_a);
	pos_in_a_pile = get_nbr_move_to_be_sort_medium((*pile_b)->value, *pile_a);
	size_a_pile = ft_pilesize(*pile_a);
	rev = 0;
	if (pos_in_a_pile > size_a_pile / 2)
	{
		rev = 1;
		pos_in_a_pile = size_a_pile - pos_in_a_pile;
	}
	i = -1;
	while (++i < pos_in_a_pile)
	{
		if (rev)
			rra(pile_a);
		else
			ra(pile_a);
	}
	pa(pile_b, pile_a);
}

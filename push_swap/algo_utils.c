/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:09:56 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/11 19:24:21 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_pile *pile)
{
	int	curr;

	if (pile)
	{
		curr = pile->value;
		while (pile->next)
		{
			pile = pile->next;
			if (pile->value > curr)
				curr = pile->value;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

int	ft_pilesize(t_pile *pile)
{
	int	c;

	c = 0;
	while (pile)
	{
		c++;
		pile = pile->next;
	}
	return (c);
}

int	calculate_best_move(t_pile *pile_a, t_pile *pile_b)
{
	int	min_moves;
	int	curr_moves;
	int	i;
	int	pos;
	int	tmp;

	min_moves = -1;
	i = 0;
	while (pile_a)
	{
		curr_moves = i;
		tmp = get_nbr_move_to_be_sort(pile_a->value, pile_b);
		if (tmp > ft_pilesize(pile_b) / 2)
			tmp = ft_pilesize(pile_b) - tmp;
		curr_moves += tmp;
		if (curr_moves < min_moves || min_moves == -1)
		{
			min_moves = curr_moves;
			pos = i;
		}
		i++;
		pile_a = pile_a->next;
	}
	return (pos);
}

int	get_nbr_move_to_be_sort(int v, t_pile *b)
{
	int		moves;
	int		min;
	int		max;

	min = get_pile_min_value(b);
	max = get_pile_max_value(b);
	moves = 0;
	while (b->next)
	{
		if ((v < min && min == ft_pilelast(b)->value
				&& max == b->value)
			|| (v > b->value && v < ft_pilelast(b)->value)
			|| (v > max && b->value == max))
			break ;
		moves++;
		if (v < min && b->value == min)
			break ;
		if (v < b->value && v > b->next->value)
			break ;
		b = b->next;
	}
	return (moves);
}

void	make_best_move(t_pile **pile_a, t_pile **pile_b, int pos)
{
	int	pos_in_b_pile;
	int	size_b_pile;
	int	i;
	int	rev;

	while (--pos >= 0)
		ra(pile_a);
	pos_in_b_pile = get_nbr_move_to_be_sort((*pile_a)->value, *pile_b);
	size_b_pile = ft_pilesize(*pile_b);
	rev = 0;
	if (pos_in_b_pile > size_b_pile / 2)
	{
		rev = 1;
		pos_in_b_pile = size_b_pile - pos_in_b_pile;
	}
	i = -1;
	while (++i < pos_in_b_pile)
	{
		if (rev)
			rrb(pile_b);
		else
			rb(pile_b);
	}
	pb(pile_a, pile_b);
}

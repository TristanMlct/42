/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:09:56 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/26 01:04:27 by tmilcent         ###   ########.fr       */
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

	min_moves = -1;
	i = 0;
	while (pile_a)
	{
		curr_moves = i;
		curr_moves += get_nbr_move_to_be_sort(pile_a->value, pile_b);
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
	t_pile	*tmp_pile;

	tmp_pile = b;
	min = b->value;
	max = b->value;
	while (tmp_pile->next)
	{
		tmp_pile = tmp_pile->next;
		if (tmp_pile->value > max)
			max = tmp_pile->value;
		if (tmp_pile->value < min)
			min = tmp_pile->value;
	}
	moves = 0;
	while (b->next && !(v > max && b->value == max)
		&& !(v > min && b->value == min)
		&& !(v < b->value && v > b->next->value))
	{
		b = b->next;
		moves++;
	}
	return (moves);
}

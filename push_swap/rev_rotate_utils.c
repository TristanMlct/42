/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:41:29 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/25 17:20:46 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_pile(t_pile **pile)
{
	t_pile	*last;
	t_pile	*tmp;

	last = ft_pilelast(*pile);
	tmp = *pile;
	while (tmp->next && tmp->next != last)
		tmp = tmp->next;
	tmp->next = 0;
	last->next = *pile;
	*pile = last;
}

void	rra(t_pile **pile_a)
{
	rev_rotate_pile(pile_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_pile **pile_b)
{
	rev_rotate_pile(pile_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	rev_rotate_pile(pile_a);
	rev_rotate_pile(pile_b);
	ft_putendl_fd("rrr", 1);
}

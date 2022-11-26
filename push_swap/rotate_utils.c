/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:41:29 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/25 17:16:18 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_pile(t_pile **pile)
{
	t_pile	*last;
	t_pile	*tmp;

	last = ft_pilelast(*pile);
	last->next = *pile;
	tmp = (*pile)->next;
	(*pile)->next = 0;
	*pile = tmp;
}

void	ra(t_pile **pile_a)
{
	rotate_pile(pile_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_pile **pile_b)
{
	rotate_pile(pile_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_pile **pile_a, t_pile **pile_b)
{
	rotate_pile(pile_a);
	rotate_pile(pile_b);
	ft_putendl_fd("rr", 1);
}

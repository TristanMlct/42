/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:33:29 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/25 17:16:40 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first(t_pile **pile)
{
	t_pile	*tmp;

	if (pile && *pile && (*pile)->next)
	{
		tmp = (*pile)->next;
		(*pile)->next = tmp->next;
		tmp->next = *pile;
		*pile = tmp;
	}
}

void	sa(t_pile **pile_a)
{
	swap_first(pile_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_pile **pile_b)
{
	swap_first(pile_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	swap_first(pile_a);
	swap_first(pile_b);
	ft_putendl_fd("ss", 1);
}

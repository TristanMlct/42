/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:42:41 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/25 17:21:11 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_first(t_pile **src, t_pile **dst)
{
	t_pile	*tmp;

	if (src && *src && dst)
	{
		tmp = (*src)->next;
		(*src)->next = *dst;
		*dst = *src;
		*src = tmp;
	}
}

void	pa(t_pile **pile_b, t_pile **pile_a)
{
	push_first(pile_b, pile_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_pile **pile_a, t_pile **pile_b)
{
	push_first(pile_a, pile_b);
	ft_putendl_fd("pb", 1);
}

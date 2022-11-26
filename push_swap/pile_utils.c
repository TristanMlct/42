/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:09:44 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/23 15:23:03 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_pilenew(int value)
{
	t_pile	*r;

	r = malloc(sizeof(t_pile));
	if (!r)
		return (0);
	r->value = value;
	r->next = 0;
	return (r);
}

void	ft_pileadd_back(t_pile **pile, t_pile *new)
{
	t_pile	*last_elem;

	if (pile)
	{
		if (*pile)
		{
			last_elem = ft_pilelast(*pile);
			last_elem->next = new;
		}
		else
		{
			*pile = new;
		}	
	}
}

t_pile	*ft_pilelast(t_pile *pile)
{
	while (pile)
	{
		if (!pile->next)
			return (pile);
		pile = pile->next;
	}
	return (pile);
}

void	ft_pileprint(t_pile *pile_a, t_pile *pile_b)
{
	ft_printf("_______________\n");
	while (pile_a)
	{
		ft_printf("%d      | ", pile_a->value);
		if (pile_b)
		{
			ft_printf("%d", pile_b->value);
			pile_b = pile_b->next;
		}
		ft_printf("\n");
		pile_a = pile_a->next;
	}
	while (pile_b)
	{
		ft_printf("       | %d\n", pile_b->value);
		pile_b = pile_b->next;
	}
	ft_printf("_______________\n");
	ft_printf("pile a | pile b\n");
}

void	ft_pileclear(t_pile **pile)
{
	t_pile	*elem;

	if (!pile)
		return ;
	while (*pile)
	{
		elem = *pile;
		*pile = (*pile)->next;
		free(elem);
	}
}

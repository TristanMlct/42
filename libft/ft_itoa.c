/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 00:14:10 by tmilcent          #+#    #+#             */
/*   Updated: 2022/10/24 14:18:16 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int n)
{
	int			c;
	long int	copy;

	c = 0;
	copy = n;
	if (n < 0)
	{
		c++;
		copy *= -1;
	}
	while (copy / 10 != 0)
	{
		c++;
		copy /= 10;
	}
	return (c + 1);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			size;
	int			min;
	long int	copy;

	size = nbr_len(n);
	s = malloc((size + 1) * sizeof(char));
	s[size] = '\0';
	min = 0;
	copy = n;
	if (n < 0)
	{
		s[0] = '-';
		copy *= -1;
		min++;
	}
	if (size == 1 && copy == 0)
		s[0] = '0';
	while (copy != 0 && --size >= min)
	{
		s[size] = (copy % 10) + '0';
		copy /= 10;
	}
	return (s);
}

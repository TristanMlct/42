/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:54:18 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/13 13:06:58 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	nbr_len(unsigned int n)
{
	int					c;
	long unsigned int	copy;

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

char	*ft_uitoa(unsigned int n)
{
	char				*s;
	int					size;
	int					min;
	long unsigned int	copy;

	size = nbr_len(n);
	s = malloc((size + 1) * sizeof(char));
	if (!s)
		return (0);
	s[size] = '\0';
	min = 0;
	copy = n;
	if (n < 0 && ++min)
	{
		s[0] = '-';
		copy *= -1;
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

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_ptr_hex(void *ptr)
{
	unsigned long long	arg;
	char				to_print[16];
	int					c;
	char				*hex;

	hex = "0123456789abcdef";
	arg = (unsigned long long)ptr;
	c = 0;
	if (arg == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	while (arg > 0)
	{
		to_print[c] = hex[arg % 16];
		arg /= 16;
		c++;
	}
	to_print[c] = '\0';
	ft_putstr_fd("0x", 1);
	while (--c >= 0)
		ft_putchar_fd(to_print[c], 1);
	return (ft_strlen(to_print) + 2);
}

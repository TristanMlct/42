/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:14:46 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/11 12:50:36 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	print_char(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}

int	print_string(va_list args)
{
	char	*to_print;

	to_print = va_arg(args, char *);
	ft_putstr_fd(to_print, 1);
	return (ft_strlen(to_print));
}

int	print_ptr_hex(va_list args)
{
	unsigned long long	arg;
	char				to_print[13];
	int					c;

	to_print[12] = '\0';
	arg = (unsigned long long)va_arg(args, void *);
	c = 0;
	while (arg > 0)
	{
		to_print[c] = arg % 16;
		if (to_print[c] < 10)
			to_print[c] += '0';
		else
			to_print[c] += 'a' - 10;
		arg /= 16;
		c++;
	}
	c--;
	while (++c < 12)
		to_print[c] = '0';
	ft_putstr_fd("0x", 1);
	while (--c >= 0)
		ft_putchar_fd(to_print[c], 1);
	return (14);
}

int	print_int(va_list args)
{
	int		r;
	char	*str;

	str = ft_itoa(va_arg(args, int));
	ft_putstr_fd(str, 1);
	r = ft_strlen(str);
	return (r); 
}

int	print_format(char c, va_list args)
{
	if (c == 'c')
		return (print_char(args));
	else if (c == 's')
		return (print_string(args));
	else if (c == 'p')
		return (print_ptr_hex(args));
	else if (c == 'd' || c == 'i')
		return (print_int(args));
	// else if (c == 'u')
	// 	return (print_int(args));
	// else if (c == 'x')
	// 	return (print_int(args));
	// else if (c == 'X')
	// 	return (print_int(args));
	// else if (c == '%')
	// 	return (print_int(args));
	// else
	// {
	// 	error
	// }
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		c;

	va_start(args, str);
	i = -1;
	c = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			c += print_format(str[++i], args);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			c++;
		}
	}
	va_end(args);
	return (c);
}

int	main(void)
{
	char *ptr = "non";
	printf("%d\n", ft_printf("%d %i %d \n", 1, 25, 123));
	printf("%d\n", printf("%d %i %d \n", 1, 25, 123));
}
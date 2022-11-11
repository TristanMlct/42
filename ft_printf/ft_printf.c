/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:14:46 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/12 00:19:15 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_ptr_hex(void *ptr)
{
	unsigned long long	arg;
	char				to_print[13];
	int					c;

	to_print[12] = '\0';
	arg = (unsigned long long)ptr;
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

int	print_int(int nb)
{
	int		r;
	char	*str;

	str = ft_itoa(nb);
	ft_putstr_fd(str, 1);
	r = ft_strlen(str);
	return (r); 
}

int	print_format(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (print_ptr_hex(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int)));
	// else if (c == 'u')
	// 	return (print_int(args));
	// else if (c == 'x')
	// 	return (print_int(args));
	// else if (c == 'X')
		// return (print_int(args));
	else if (c == '%')
		return (print_char('%'));
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
	// c
	printf("%d\n", ft_printf("%c %c \n", 'a', '\n'));
	printf("%d\n", printf("%c %c \n", 'a', '\n'));
	// s
	printf("%d\n", ft_printf("%s %s \n", "test", "aaa\n"));
	printf("%d\n", printf("%s %s \n", "test", "aaa\n"));
	// p
	printf("%d\n", ft_printf("%p \n", ptr));
	printf("%d\n", printf("%p \n", ptr));
	// d && i
	printf("%d\n", ft_printf("%d %i %d \n", 2147483647, 25, 123));
	printf("%d\n", printf("%d %i %d \n", 2147483647, 25, 123));
	// u
	// printf("%d\n", ft_printf("%d %i %d \n", 1, 25, 123));
	// printf("%d\n", printf("%u \n", 2147483648));
	// x
	// printf("%d\n", ft_printf("%d %i %d \n", 1, 25, 123));
	printf("%d\n", printf("%x \n", 494967295));
	// X
	// printf("%d\n", ft_printf("%d %i %d \n", 1, 25, 123));
	printf("%d\n", printf("%X \n", 494967295));
	// %
	printf("%d\n", ft_printf("%% \n"));
	printf("%d\n", printf("%% \n"));
}
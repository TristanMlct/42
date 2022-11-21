/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:47:41 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/20 22:07:55 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		print_nbr_len(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		print_char(int c);
int		print_string(char *str);
int		print_ptr_hex(void *ptr);
int		print_int(int nb);
int		print_unsigned_int(unsigned int nb);
int		print_hex(unsigned int nb, char type);
int		print_format(char c, va_list args);
int		ft_printf(const char *str, ...);

#endif
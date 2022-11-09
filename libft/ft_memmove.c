/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:05:13 by tmilcent          #+#    #+#             */
/*   Updated: 2022/10/16 21:05:14 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dest < src)
	{
		while (++i < n)
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	}
	else
	{
		while (++i < n)
			*(unsigned char *)(dest + n - 1 - i)
				= *(unsigned char *)(src + n - 1 - i);
	}
	return (dest);
}

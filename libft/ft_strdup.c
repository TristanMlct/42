/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:54:55 by tmilcent          #+#    #+#             */
/*   Updated: 2022/10/21 14:05:27 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = ft_strlen(str);
	dup = malloc(sizeof(char) * (i + 1));
	while (i >= 0)
	{
		dup[i] = str[i];
		i--;
	}
	return (dup);
}

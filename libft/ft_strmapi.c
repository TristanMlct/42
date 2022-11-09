/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:26:57 by tmilcent          #+#    #+#             */
/*   Updated: 2022/10/24 23:17:56 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;

	r = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!r)
		return (0);
	i = -1;
	while (s[++i])
	{
		r[i] = f(i, s[i]);
	}
	r[i] = '\0';
	return (r);
}

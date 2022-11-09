/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:27:20 by tmilcent          #+#    #+#             */
/*   Updated: 2022/10/23 18:14:48 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_charset(char c, char const *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len_s1;
	int		i;
	char	*r;

	start = 0;
	while (s1[start] && is_in_charset(s1[start], set))
		start++;
	len_s1 = ft_strlen(s1);
	end = len_s1 - 1;
	while (s1[end] && is_in_charset(s1[end], set))
		end--;
	r = malloc((end - start + 2) * sizeof(char));
	if (!r)
		return (0);
	i = -1;
	while (++i + start <= end)
		r[i] = s1[start + i];
	r[i] = '\0';
	return (r);
}

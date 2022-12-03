/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:18:31 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/03 18:15:08 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

double	deg_to_rad(int degree)
{
	return (degree * 3.14159265 / 180.0);
}

void	free_map(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i < fdf->map.lines)
	{
		free(fdf->map.map[i]);
		free(fdf->map.points[i]);
	}
	free(fdf->map.map);
	free(fdf->map.points);
}

t_point	calculate_iso_position(int x, int y)
{
	t_point	point;

	point.x = x * cos(deg_to_rad(30)) + y * cos(deg_to_rad(150));
	point.y = x * sin(deg_to_rad(30)) + y * sin(deg_to_rad(150));
	return (point);
}

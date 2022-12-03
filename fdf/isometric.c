/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 00:07:02 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/03 22:49:52 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_points(t_fdf *fdf)
{
	int		i;
	int		j;

	fdf->map.offset.x = calculate_iso_position(0, fdf->map.lines - 1).x;
	fdf->map.offset.y = 0;
	i = -1;
	fdf->map.points = malloc(sizeof(t_point *) * fdf->map.lines);
	while (++i < fdf->map.lines)
	{
		fdf->map.points[i] = malloc(sizeof(t_point) * fdf->map.cols);
		j = -1;
		while (++j < fdf->map.cols)
		{
			fdf->map.points[i][j] = calculate_iso_position(j, i);
			if (fdf->map.points[i][j].y < fdf->map.offset.y)
				fdf->map.offset.y = fdf->map.points[i][j].y;
		}
	}
}

void	apply_offset(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	new_offset;

	new_offset.x = 0;
	new_offset.y = 0;
	i = -1;
	while (++i < fdf->map.lines)
	{
		j = -1;
		while (++j < fdf->map.cols)
		{
			fdf->map.points[i][j].x -= fdf->map.offset.x;
			fdf->map.points[i][j].y -= fdf->map.offset.y;
			if (fdf->map.points[i][j].x > new_offset.x)
				new_offset.x = fdf->map.points[i][j].x;
			if (fdf->map.points[i][j].y > new_offset.y)
				new_offset.y = fdf->map.points[i][j].y;
		}
	}
	fdf->map.offset.x = new_offset.x;
	fdf->map.offset.y = new_offset.y;
}

void	calculate_zoom(t_fdf *fdf)
{
	int		i;
	int		j;
	double	zoom;

	zoom = floor(fmin((W_HEIGT - 100)
				/ fdf->map.points[fdf->map.lines - 1][fdf->map.cols - 1].y,
				(W_WIDTH - 100) / fdf->map.points[0][fdf->map.cols - 1].x));
	i = -1;
	while (++i < fdf->map.lines)
	{
		j = -1;
		while (++j < fdf->map.cols)
		{
			fdf->map.points[i][j].x *= zoom;
			fdf->map.points[i][j].y *= zoom;
			fdf->map.map[i][j] *= zoom / 20;
		}
	}
	fdf->map.offset.x *= zoom;
	fdf->map.offset.y *= zoom;
}

void	align_fdf(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	offset;

	offset.x = ((W_WIDTH - fdf->map.offset.x) / 2);
	offset.y = ((W_HEIGT - fdf->map.offset.y) / 2);
	i = -1;
	while (++i < fdf->map.lines)
	{
		j = -1;
		while (++j < fdf->map.cols)
		{
			fdf->map.points[i][j].x += offset.x;
			fdf->map.points[i][j].y += offset.y - fdf->map.map[i][j];
		}
	}
}

void	print_map(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->map.lines)
	{
		j = -1;
		while (++j < fdf->map.cols)
		{
			if (i != 0)
				draw_line(&fdf->mlx.image, fdf->map.points[i][j],
					fdf->map.points[i - 1][j], WHITE);
			if (j != 0)
				draw_line(&fdf->mlx.image, fdf->map.points[i][j],
					fdf->map.points[i][j - 1], WHITE);
			if (i != fdf->map.lines - 1)
				draw_line(&fdf->mlx.image, fdf->map.points[i][j],
					fdf->map.points[i + 1][j], WHITE);
			if (j != fdf->map.cols - 1)
				draw_line(&fdf->mlx.image, fdf->map.points[i][j],
					fdf->map.points[i][j + 1], WHITE);
		}
	}
}

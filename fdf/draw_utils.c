/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:11:53 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/03 22:50:11 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (y >= 0)
	{
		dst = img->addr + (y * img->line_length
				+ x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

t_point	init_point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	draw_line(t_data *img, t_point a, t_point b, int color)
{
	float	i;
	float	tmp;
	float	tmp2;
	float	step;

	step = fmaxf(ft_abs((float) b.x - (float) a.x),
			ft_abs((float) b.y - (float) a.y));
	i = -1;
	while (++i <= step)
	{
		tmp = (float) a.x + ((float)(b.x - a.x) / step) * i;
		tmp2 = (float) a.y + ((float)(b.y - a.y) / step) * i;
		put_pixel(img, (int) roundf(tmp),
			(int) roundf(tmp2), color);
	}
}

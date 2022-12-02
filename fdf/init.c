/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:44:40 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/30 23:45:45 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx.mlx = mlx_init();
	fdf->mlx.window = mlx_new_window(fdf->mlx.mlx, W_WIDTH, W_HEIGT, "Fdf");
	fdf->mlx.image.img = mlx_new_image(fdf->mlx.mlx, W_WIDTH, W_HEIGT);
	fdf->mlx.image.addr = mlx_get_data_addr(fdf->mlx.image.img,
		&fdf->mlx.image.bits_per_pixel, &fdf->mlx.image.line_length,
		&fdf->mlx.image.endian);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.window,
		fdf->mlx.image.img, 0, 0);
	mlx_loop(fdf->mlx.mlx);
}

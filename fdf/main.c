/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:52:07 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/03 22:49:31 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;
	int		r;

	if (argc == 2)
	{
		ft_bzero(&fdf, sizeof(t_fdf));
		if (is_map_valid(argv[1], &fdf))
		{
			init_fdf(&fdf);
			init_points(&fdf);
			apply_offset(&fdf);
			calculate_zoom(&fdf);
			align_fdf(&fdf);
			print_map(&fdf);
			mlx_put_image_to_window(fdf.mlx.mlx, fdf.mlx.window,
				fdf.mlx.image.img, 0, 0);
			mlx_loop(fdf.mlx.mlx);
			free_map(&fdf);
		}
		else
			ft_printf("Map not valid !\n");
	}
	else
		ft_printf("usage: %s ./fdf *.fdf\n", argv[0]);
	return (0);
}

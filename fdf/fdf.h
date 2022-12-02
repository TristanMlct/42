/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:02:22 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/02 12:41:09 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

# define WHITE 0x00FFFFFF
# define W_WIDTH 1000
# define W_HEIGT 500

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_data	image;
}	t_mlx;

typedef struct s_map
{
	int	**map;
}	t_map;


typedef struct s_fdf
{
	t_mlx	mlx;
	t_map	map;
}	t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/*
	draw_utils.c
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_data *img, t_point a, t_point b, int color);
t_point	init_point(int x, int y);

/*
	utils.c
*/
float	ft_abs(float a);

/*
	init.c
*/
void	init_fdf(t_fdf *fdf);

/*
	parsing.c
*/
int	is_map_valid(char *map_file, t_fdf *fdf);

#endif

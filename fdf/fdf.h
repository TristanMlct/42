/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:02:22 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/03 22:50:44 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

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

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_map
{
	int		**map;
	t_point	**points;
	t_point	offset;
	int		lines;
	int		cols;
}	t_map;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_map	map;
}	t_fdf;

/*
	draw_utils.c
*/
void	put_pixel(t_data *img, int x, int y, int color);
void	draw_line(t_data *img, t_point a, t_point b, int color);
t_point	init_point(int x, int y);

/*
	utils.c
*/
float	ft_abs(float a);
double	deg_to_rad(int degree);
void	free_map(t_fdf *fdf);
t_point	calculate_iso_position(int x, int y);

/*
	init.c
*/
void	init_fdf(t_fdf *fdf);

/*
	parsing.c
*/
int		is_map_valid(char *map_file, t_fdf *fdf);

/*
	isometric.c
*/
void	print_map(t_fdf *fdf);
void	calculate_zoom(t_fdf *fdf);
void	apply_offset(t_fdf *fdf);
void	align_fdf(t_fdf *fdf);
void	init_points(t_fdf *fdf);

#endif

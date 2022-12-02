/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:52:07 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/30 23:50:45 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;
	int		r;

	r = 1;
	if (argc == 2)
	{
		ft_bzero(&fdf, sizeof(t_fdf));
		if (is_map_valid(argv[1], &fdf))
		{
			init_fdf(&fdf);
		}
		else
		{
			// free map
			ft_printf("Map not valid !\n");
		}
	}
	else
		ft_printf("usage: %s ./fdf *.fdf\n", argv[0]);
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:16:44 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/02 12:39:37 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_map_valid(char *map_file, t_fdf *fdf)
{
	char	*curr_line;
	int		fd;
	int		c;
	
	fd = open(map_file, O_RDONLY);
	c = 0;
	curr_line = get_next_line(fd);
	while (curr_line)
	{
		c++;
		curr_line = get_next_line(fd);
	}
	
}
 
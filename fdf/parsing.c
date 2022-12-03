/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:16:44 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/02 21:42:05 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char const *s, char c)
{
	int	in_word;
	int	count;
	int	i;

	count = 0;
	in_word = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
	}
	return (count);
}

static int	count_and_check_lines(char *map_file, t_fdf *fdf)
{
	int		c;
	int		fd;
	char	*curr_line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	c = 0;
	curr_line = get_next_line(fd);
	fdf->map.cols = count_words(curr_line, ' ');
	while (curr_line)
	{
		c++;
		free(curr_line);
		curr_line = get_next_line(fd);
		if (curr_line && count_words(curr_line, ' ') != fdf->map.cols)
		{
			free(curr_line);
			return (0);
		}
	}
	close(fd);
	return (c);
}

static void	fill_map(int fd, t_fdf *fdf)
{
	int		i;
	int		j;
	char	*curr_line;
	char	**curr_split;

	fdf->map.map = malloc(sizeof(int *) * fdf->map.lines);
	i = -1;
	while (++i < fdf->map.lines)
	{
		fdf->map.map[i] = malloc(sizeof(int) * fdf->map.cols);
		curr_line = get_next_line(fd);
		curr_split = ft_split(curr_line, ' ');
		j = -1;
		while (curr_split[++j])
		{
			fdf->map.map[i][j] = ft_atoi(curr_split[j]);
			free(curr_split[j]);
		}
		free(curr_line);
		free(curr_split);
	}
}

int	is_map_valid(char *map_file, t_fdf *fdf)
{
	int		fd;

	fdf->map.lines = count_and_check_lines(map_file, fdf);
	if (!fdf->map.lines)
		return (0);
	fd = open(map_file, O_RDONLY);
	fill_map(fd, fdf);
	close(fd);
	return (1);
}

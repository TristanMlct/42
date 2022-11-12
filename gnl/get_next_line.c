/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:55:42 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/12 23:45:26 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char	*current_line = 0;
	char		buffer[BUFFER_SIZE];
	ssize_t		size;
	char		*tmp;

	if (current_line != 0 && is_bn_in_str(current_line))
	{
		// => read current_line till bn and return it
	}
	else
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (current_line != 0)
		{
			tmp = ft_strdup(current_line);
			free(current_line);
			current_line = malloc((ft_strlen(tmp) + size) * sizeof(char));
			ft_strlcat(current_line, tmp, ft_strlen(tmp));
			ft_strlcat(current_line, buffer, size);
		}
		else
		{
			current_line = malloc((ft_strlen(tmp) + size) * sizeof(char));
			
		}
		// read the fd
		// if (current_line != 0)
		// => add buffer to current line
		// else
		// => create current_line
		// => add the buffer to it
		// then
		// => read current_line till bn and return it
	}
}
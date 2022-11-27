/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:28 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/27 09:13:14 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_join(char *s1, char *s2, int size);
char	*find_line(char *str);
char	*remove_first_line(char *str);
char	*init_curr_line(void);
char	*get_next_line(int fd);
int		is_bn_in_line(char *str);
int		ft_strlen(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:41:22 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/21 13:29:18 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_pile
{
	int				value;
	struct s_pile	*next;
}	t_pile;

/*
	args.c
*/
int	check_args(int argc, char *argv[]);
int	check_args_as_str(char *str);

/*
	error.c
*/
int	error(void);

#endif
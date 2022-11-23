/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:41:22 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/23 13:25:45 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_args
{
	int	*tab_int;
	int	nb;
}	t_args;

typedef struct s_pile
{
	int				value;
	struct s_pile	*next;
}	t_pile;

/*
	args.c
*/
int		check_args(t_args *args, int argc, char *argv[]);
int		check_args_chars(t_args *args, char *str[]);
void	check_args_as_str(t_args *args, char *str);
void	check_args_as_int(t_args *args, int argc, char *argv[]);
void	check_doublons(t_args *args);

/*
	error.c
*/
int		print_error(void);

/*
	utils.c
*/
int		ft_isint(char *str);
void	free_tabstr(char *tab_str[]);

/*
	pile_utils.c
*/
t_pile	*ft_pilenew(int value);
void	ft_pileadd_back(t_pile **pile, t_pile *new);
t_pile	*ft_pilelast(t_pile *pile);
void	ft_pileprint(t_pile *pile);
void	ft_pileclear(t_pile **pile);

#endif
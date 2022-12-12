/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:41:22 by tmilcent          #+#    #+#             */
/*   Updated: 2022/12/12 19:26:32 by tmilcent         ###   ########.fr       */
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
	push_swap.c
*/
void	init_piles(t_pile **pile_a, t_pile **pile_b, t_args *args);
void	perform_algo(t_pile **pile_a, t_pile **pile_b);
void	finish_algo(t_pile **pile_a, t_pile **pile_b);

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
int		get_pile_max_value(t_pile *pile);
int		get_pile_min_value(t_pile *pile);
int		is_correct(char *str);

/*
	pile_utils.c
*/
t_pile	*ft_pilenew(int value);
void	ft_pileadd_back(t_pile **pile, t_pile *new);
t_pile	*ft_pilelast(t_pile *pile);
void	ft_pileprint(t_pile *pile_a, t_pile *pile_b);
void	ft_pileclear(t_pile **pile);

/*
	swap_utils.c
*/
void	swap_first(t_pile **pile);
void	sa(t_pile **pile_a);
void	sb(t_pile **pile_b);
void	ss(t_pile **pile_a, t_pile **pile_b);

/*
	push_utils.c
*/
void	push_first(t_pile **src, t_pile **dst);
void	pa(t_pile **pile_b, t_pile **pile_a);
void	pb(t_pile **pile_a, t_pile **pile_b);

/*
	rotate_utils.c
*/
void	rotate_pile(t_pile **pile);
void	ra(t_pile **pile_a);
void	rb(t_pile **pile_b);
void	rr(t_pile **pile_a, t_pile **pile_b);

/*
	rev_rotate_utils.c
*/
void	rev_rotate_pile(t_pile **pile);
void	rra(t_pile **pile_a);
void	rrb(t_pile **pile_b);
void	rrr(t_pile **pile_a, t_pile **pile_b);

/*
	algo_utils.c
*/
int		is_sorted(t_pile *pile);
int		ft_pilesize(t_pile *pile);
int		calculate_best_move(t_pile *pile_a, t_pile *pile_b);
int		get_nbr_move_to_be_sort(int v, t_pile *b);
void	make_best_move(t_pile **pile_a, t_pile **pile_b, int pos);

/*
	other_algo.c
*/
void	small_pile_algo(t_pile **pile_a);
void	medium_pile_algo(t_pile **pile_a, t_pile **pile_b);
int		calculate_best_move_medium(t_pile *pile_a, t_pile *pile_b);
int		get_nbr_move_to_be_sort_medium(int v, t_pile *a);
void	make_best_move_medium(t_pile **pile_a, t_pile **pile_b, int pos);

#endif
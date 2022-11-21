/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:15:48 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/22 00:04:15 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(t_args *args, int argc, char *argv[])
{
	if (argc == 2)
		check_args_as_str(args, argv[1]);
	else if (argc > 2)
		check_args_as_int(args, argc, argv);
	if (!args->tab_int)
	{
		free(args);
		return (print_error());
	}
	return (1);
}

int	check_args_chars(t_args *args, char *str[])
{
	int	i;
	int	j;

	i = -1;
	while (++i < args->nb)
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != '-' && str[i][j] != '+'
			&& str[i][j] != ' ' && !(str[i][j] >= 9 && str[i][j] <= 13))
			{
				return (0);
			}
			j++;
		}
	}
	return (1);
}

void	check_args_as_str(t_args *args, char *str)
{
	int		i;
	char	**tab_str;

	tab_str = ft_split(str, ' ');
	i = 0;
	while (tab_str[i])
		i++;
	args->nb = i;
	if (!check_args_chars(args, tab_str))
		return (free_tabstr(tab_str));
	args->tab_int = malloc(sizeof(int) * i);
	i = -1;
	while (++i < args->nb)
	{
		if (!ft_isint(tab_str[i]))
		{
			free(args->tab_int);
			args->tab_int = 0;
			return (free_tabstr(tab_str));
		}
		args->tab_int[i] = ft_atoi(tab_str[i]);
	}
	free_tabstr(tab_str);
	check_doublons(args);
}

void	check_args_as_int(t_args *args, int argc, char *argv[])
{
	int	i;

	args->nb = argc - 1;
	if (!check_args_chars(args, &argv[1]))
		return ;
	args->tab_int = malloc(sizeof(int) * (args->nb));
	i = -1;
	while (++i < args->nb)
	{
		if (!ft_isint(argv[i + 1]))
		{
			free(args->tab_int);
			args->tab_int = 0;
			return ;
		}
		args->tab_int[i] = ft_atoi(argv[i + 1]);
	}
	check_doublons(args);
}

void	check_doublons(t_args *args)
{
	int	i;
	int	j;

	i = -1;
	while (++i < args->nb)
	{
		j = i;
		while (++j < args->nb)
		{
			if (args->tab_int[i] == args->tab_int[j])
			{
				free(args->tab_int);
				args->tab_int = 0;
				return ;
			}
		}
	}
}

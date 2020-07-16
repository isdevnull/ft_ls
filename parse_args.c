/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:20:56 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/08 22:20:57 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		manage_time(int *flags, char arg)
{
	if (arg == 't')
		*flags |= FLAG_TIME;
	else if (arg == 'u')
	{
		*flags |= FLAG_LA;
		*flags &= ~FLAG_FC;
	}
	else if (arg == 'U')
	{
		*flags |= FLAG_FC;
		*flags &= ~FLAG_LA;
	}
}

static void		display_usage(char option)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(USAGE, 2);
	ft_putchar_fd('\n', 2);
	exit(-1);
}

static void		fill_flag(int *flags, char arg)
{
	if (arg == 'l')
		*flags |= FLAG_LONG;
	else if (arg == 'a')
		*flags |= FLAG_ALL;
	else if (arg == 'r')
		*flags |= FLAG_REVERSE;
	else if (arg == 'R')
		*flags |= FLAG_RECURSION;
	else if (arg == 's')
		*flags |= FLAG_S;
	else if (arg == 'S')
		*flags |= FLAG_BIG_S;
	else if (arg == 't' || arg == 'u' || arg == 'U')
		manage_time(flags, arg);
	else if (arg == '@')
		*flags |= FLAG_XATTR;
	else
		*flags = ILLEGAL_OPTION;
}

int				parse_args(int ac, char **av, int *flags)
{
	int	i;
	int j;

	*flags = 0;
	if (ac == 1)
		return (0);
	i = 1;
	while (i < ac && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			fill_flag(flags, av[i][j]);
			if (*flags == ILLEGAL_OPTION)
				display_usage(av[i][j]);
			j++;
		}
		i++;
	}
	return (i);
}

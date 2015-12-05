/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 03:30:52 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/07 12:49:32 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_option(char c)
{
	ft_putstr_fd("push_swap: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: push_swap [-bclv] [numbers ...]\n", 2);
}

int		check_options(char c, t_opt *options)
{
	if (c == 'v')
		options->v = 1;
	else if (c == 'c')
		options->c = 1;
	else if (c == 'b')
		options->b = 1;
	else if (c == 'l')
		options->l = 1;
	else if (c == 'r')
		options->r = 1;
	else if (c == '-' && options->end == 0)
		options->end = 1;
	else
	{
		print_error_option(c);
		return (0);
	}
	return (1);
}

void	init_options(t_opt *options)
{
	options->pusha = 0;
	options->pushb = 0;
	options->swap = 0;
	options->rrotate = 0;
	options->rotate = 0;
	options->c = 0;
	options->v = 0;
	options->b = 0;
	options->l = 0;
	options->r = 0;
	options->end = 0;
}

int		go_option(char *str, t_opt *options)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && options->end == 1)
		{
			print_error_option('-');
			exit(-1);
		}
		if (check_options(str[i], options) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		fill_options(int ac, char **av, t_opt *options)
{
	int i;
	int ret;

	i = 1;
	while (i < ac && options->end == 0)
	{
		if (!ft_strncmp(av[i], "-", 1) && ft_strlen(av[i]) > 1)
		{
			if ((ret = go_option(av[i], options)) == 0)
				return (0);
		}
		else
			return (i);
		i++;
	}
	return (i);
}

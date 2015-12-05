/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 01:24:32 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/07 13:37:56 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		make_piles(int ints[2], char **av, t_pile **a, t_opt opts)
{
	int	i;
	int error;

	i = ints[1] - 1;
	while (i > ints[0] - 1)
	{
		if ((error = check_error(av[i], *a)) == 1)
		{
			if (*a == NULL)
				*a = new_int(av[i]);
			else
				*a = push_front(*a, new_int(av[i]));
		}
		else
			exit_error(error);
		i--;
	}
	if (is_ordereda(*a, opts.r))
		return (0);
	return (1);
}

void	run(t_pile **a, t_pile **b, t_opt opts)
{
	t_pile	*a2;
	t_pile	*b2;
	int		first;
	int		low;

	a2 = *a;
	b2 = *b;
	first = 0;
	while (!is_ordereda(a2, opts.r))
	{
		if (!opts.r)
			low = algo(&a2, &b2, &opts, first);
		else
			low = algo_reverse(&a2, &b2, &opts, first);
		print_piles(a2, b2, opts, low);
		first++;
	}
	while (b2)
	{
		push(&a2, &b2, 0, ((!opts.v) ? first : 0));
		print_piles(a2, b2, opts, -1);
		opts.pusha++;
		first++;
	}
	print_opts(first, opts);
}

void	first_step(t_opt *opts, t_pile **a, t_pile **b)
{
	init_options(opts);
	*a = NULL;
	*b = NULL;
}

int		main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	t_opt	opts;
	int		i[2];

	i[0] = 0;
	i[1] = ac;
	first_step(&opts, &a, &b);
	if (ac > 1)
		if ((i[0] = fill_options(ac, av, &opts)) == 0)
			return (0);
	if (ac == 1)
		exit_error(-3);
	if (make_piles(i, av, &a, opts) == 0)
		exit_error(-4);
	if (opts.v && !is_ordereda(a, opts.r))
	{
		ft_putstr("\033[32mstart:\033[0m");
		print_piles(a, b, opts, -2);
	}
	run(&a, &b, opts);
	if (!opts.v || (opts.b || opts.l))
		write(1, "\n", 1);
	return (0);
}

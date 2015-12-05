/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:30:54 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/07 13:32:53 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	color(int low, int n_pile, t_pile *temp, t_opt opts)
{
	if (opts.c)
	{
		write(1, "\033[31m", 5);
		if (low == 0 && n_pile && !temp->previous)
			write(1, "\033[32m", 5);
		else if (low == 1 && !n_pile &&
				((temp->previous && !temp->previous->previous) ||
				(!temp->previous)))
			write(1, "\033[32m", 5);
		else if (low == -1 && !n_pile && !temp->previous)
			write(1, "\033[32m", 5);
		else if (low > 1 && !n_pile)
			write(1, "\033[32m", 5);
	}
}

void	print_pile(t_pile *pile, int n_pile, int low, t_opt opts)
{
	t_pile *temp;

	if (!n_pile)
		write(1, "\033[33ma\033[0m:", 11);
	else
		write(1, "\n\033[35mb\033[0m:", 12);
	temp = pile;
	if (pile == NULL)
		return ;
	while (temp->next)
		temp = temp->next;
	while (temp)
	{
		color(low, n_pile, temp, opts);
		if (temp->next != NULL)
			write(1, " ", 1);
		ft_putnbr(temp->nb);
		write(1, "\033[0m", 5);
		temp = temp->previous;
	}
}

void	print_piles(t_pile *a, t_pile *b, t_opt opts, int low)
{
	if (opts.v)
	{
		if (low != -2)
			write(1, "->", 2);
		write(1, "\n", 1);
		print_pile(a, 0, low, opts);
		print_pile(b, 1, low, opts);
		if (!b)
			ft_putstr("\033[31m(null)\033[0m");
		write(1, "\n", 1);
	}
}

void	print_opts(int nb_instr, t_opt opts)
{
	if (opts.b)
	{
		write(1, "\nNombre d'instructions : ", 25);
		write(1, "\033[32m", 5);
		ft_putnbr(nb_instr);
		write(1, "\033[0m", 4);
	}
	if (opts.l)
	{
		ft_putstr("\n");
		putstr_nbr("pa: ", opts.pusha, 0);
		putstr_nbr("pb: ", opts.pushb, 1);
		putstr_nbr("sa: ", opts.swap, 1);
		putstr_nbr("sb: ", 0, 1);
		putstr_nbr("ra: ", opts.rotate, 1);
		putstr_nbr("rb: ", 0, 1);
		putstr_nbr("rra: ", opts.rrotate, 1);
		putstr_nbr("rrb: ", 0, 1);
	}
}

void	putstr_nbr(const char *str, int nb, int space)
{
	if (space)
		ft_putstr(" ");
	ft_putstr(str);
	if (nb != 0)
		write(1, "\033[32m", 5);
	else
		write(1, "\033[31m", 5);
	ft_putnbr(nb);
	write(1, "\033[0m", 4);
}

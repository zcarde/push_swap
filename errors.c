/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:29:55 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/13 09:37:50 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_error(char *str, t_pile *a)
{
	t_pile	*temp;
	long	nb;

	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (-2);
	if (a == NULL)
		return (1);
	temp = a;
	while (temp && (temp->next != a))
	{
		if (temp->nb == nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	exit_error(int error)
{
	if (error == 0)
		ft_putstr_fd("\033[31mError : Duplicate number\033[0m\n", 1);
	else if (error == -1)
		ft_putstr_fd("\033[31mError : Letters\033[0m\n", 1);
	else if (error == -2)
		ft_putstr_fd("\033[31mError : Overflow\033[0m\n", 1);
	else if (error == -3)
		ft_putstr_fd("\033[31mError\033[0m\n", 1);
	else if (error == -4)
	{
		ft_putstr("\033[32mAlready ordered\n\033[0m");
		exit (0);
	}
	exit(-1);
}

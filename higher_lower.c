/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   higher_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:33:04 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/07 13:33:18 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_lower(t_pile *a)
{
	t_pile	*temp;
	t_pile	*min;
	int		i;

	i = 0;
	temp = a;
	min = temp;
	while (temp)
	{
		if (temp->nb < min->nb)
			min = temp;
		temp = temp->next;
	}
	temp = a;
	while (temp)
	{
		if (temp == min)
			return (i);
		i++;
		temp = temp->next;
	}
	return (i);
}

int		get_higher(t_pile *a)
{
	t_pile	*temp;
	t_pile	*max;
	int		i;

	i = 0;
	temp = a;
	max = temp;
	while (temp)
	{
		if (temp->nb > max->nb)
			max = temp;
		temp = temp->next;
	}
	temp = a;
	while (temp)
	{
		if (temp == max)
			return (i);
		i++;
		temp = temp->next;
	}
	return (i);
}

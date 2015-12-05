/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:25:22 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/07 13:37:39 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile, int i, int space)
{
	int temp;

	if (space)
		write(1, " ", 1);
	if (i == 0)
		write(1, "sa", 2);
	if (i == 1)
		write(1, "sb", 2);
	if (i == 2)
		write(1, "ss", 2);
	if (*pile && (*pile)->next)
	{
		temp = (*pile)->nb;
		(*pile)->nb = (*pile)->next->nb;
		(*pile)->next->nb = temp;
	}
}

void	push(t_pile **first, t_pile **second, int i, int space)
{
	if (space)
		write(1, " ", 1);
	if (i == 0)
		write(1, "pa", 2);
	if (i == 1)
		write(1, "pb", 2);
	if (*second)
	{
		if (*first == NULL)
			*first = new_int_cpy(*second);
		else
			*first = push_front(*first, new_int_cpy(*second));
		if ((*second)->next == NULL)
			*second = NULL;
		else
			*second = remove_first(*second);
	}
}

void	rotate(t_pile **pile, int i, int space)
{
	t_pile	*temp;

	if (space)
		write(1, " ", 1);
	if (i == 0)
		write(1, "ra", 2);
	if (i == 1)
		write(1, "rb", 2);
	temp = new_int_cpy(*pile);
	*pile = remove_first(*pile);
	if (*pile == NULL)
		*pile = temp;
	else
		*pile = push_back(*pile, temp);
}

void	reverse_rotate(t_pile **pile, int i, int space)
{
	t_pile *temp;
	t_pile *temp2;

	if (space)
		write(1, " ", 1);
	if (i == 0)
		write(1, "rra", 3);
	if (i == 1)
		write(1, "rrb", 3);
	if (i == 2)
		write(1, "rrr", 3);
	temp = *pile;
	while (temp->next)
		temp = temp->next;
	temp2 = new_int_cpy(temp);
	*pile = remove_last(*pile);
	*pile = push_front(*pile, temp2);
}

t_pile	*remove_last(t_pile *src)
{
	t_pile *temp;

	temp = src;
	while (temp->next)
		temp = temp->next;
	if (temp->previous)
		temp->previous->next = NULL;
	free(temp);
	return (src);
}

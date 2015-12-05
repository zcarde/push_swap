/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_piles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:29:22 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/07 13:33:45 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*push_front(t_pile *a, t_pile *to_add)
{
	to_add->next = a;
	a->previous = to_add;
	a = to_add;
	return (a);
}

t_pile	*push_back(t_pile *a, t_pile *to_add)
{
	t_pile	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	to_add->previous = tmp;
	tmp->next = to_add;
	return (a);
}

t_pile	*new_int(char *nb)
{
	t_pile *new_pile;

	if (!(new_pile = (t_pile *)malloc(sizeof(t_pile))))
		return (NULL);
	new_pile->nb = ft_atoi(nb);
	new_pile->next = NULL;
	new_pile->previous = NULL;
	return (new_pile);
}

t_pile	*new_int_cpy(t_pile *src)
{
	t_pile *new_pile;

	if (!(new_pile = (t_pile *)malloc(sizeof(t_pile))))
		return (NULL);
	new_pile->nb = src->nb;
	new_pile->next = NULL;
	new_pile->previous = NULL;
	return (new_pile);
}

t_pile	*remove_first(t_pile *src)
{
	t_pile *temp;

	src->next->previous = NULL;
	temp = src->next;
	free(src);
	return (temp);
}

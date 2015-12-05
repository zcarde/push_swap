/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:31:48 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/07 13:35:55 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo(t_pile **a2, t_pile **b2, t_opt *opts, int first)
{
	int low;

	low = get_lower(*a2);
	if (low == 0)
	{
		opts->pushb++;
		push(b2, a2, 1, ((!opts->v) ? first : 0));
	}
	else if (low == 1)
	{
		opts->swap++;
		swap(a2, 0, ((!opts->v) ? first : 0));
	}
	else if (low == get_nb_elem(*a2))
	{
		opts->rrotate++;
		reverse_rotate(a2, 0, ((!opts->v) ? first : 0));
	}
	else
	{
		opts->rotate++;
		rotate(a2, 0, ((!opts->v) ? first : 0));
	}
	return (low);
}

int		algo_reverse(t_pile **a2, t_pile **b2, t_opt *opts, int first)
{
	int low;

	low = get_higher(*a2);
	if (low == 0)
	{
		opts->pushb++;
		push(b2, a2, 1, ((!opts->v) ? first : 0));
	}
	else if (low == 1)
	{
		opts->swap++;
		swap(a2, 0, ((!opts->v) ? first : 0));
	}
	else if (low == get_nb_elem(*a2))
	{
		opts->rrotate++;
		reverse_rotate(a2, 0, ((!opts->v) ? first : 0));
	}
	else
	{
		opts->rotate++;
		rotate(a2, 0, ((!opts->v) ? first : 0));
	}
	return (low);
}

int		get_nb_elem(t_pile *list)
{
	t_pile	*temp;
	int		i;

	i = 0;
	temp = list;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int		is_ordereda(t_pile *a, int i)
{
	t_pile *temp;

	temp = a;
	while (temp)
	{
		if (temp->next)
		{
			if (!i)
			{
				if (temp->nb > temp->next->nb)
					return (0);
			}
			else
			{
				if (temp->nb < temp->next->nb)
					return (0);
			}
		}
		temp = temp->next;
	}
	return (1);
}

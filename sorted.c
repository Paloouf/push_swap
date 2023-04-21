/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:50:44 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/21 13:15:50 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *st)
{
	int	i;

	i = 0;
	while ((i + 1) < st->len)
	{
		if (st->a[i] < st->a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_a_sorted(t_stack *st)
{
	int	i;

	i = 0;
	while ((i + 1) < st->index)
	{
		if (st->a[i] < st->a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_b_sorted(t_stack *st)
{
	int	i;

	i = 0;
	while ((i + 1) < (st->len - st->index))
	{
		if (st->b[i] > st->b[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

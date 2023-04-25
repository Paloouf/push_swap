/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:54:10 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/25 13:11:42 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	now_we_sort_better(t_stack *st)
{
	while (!is_a_sorted(st))
		r_rotate_a(st, 0);
}

void	now_we_sort_more(t_stack *st, int big, int small)
{
	while (!is_a_sorted(st))
	{
		if (st->b[0] != big && st->b[0] != small)
			r_ra_rb(st, 0);
		else
			r_rotate_a(st, 0);
	}
}

int	find_small(t_stack *st, int n, int m)
{
	int	i;
	int	small;
	int	index;

	i = 0;
	small = INT32_MAX;
	while (i < st->len - st->index)
	{
		if ((st->b[i] >= st->o[n] && st->b[i] < st->o[m]) && st->b[i] < small)
		{
			index = i;
			small = st->b[i];
		}
		i++;
	}
	return (index);
}

int	find_big(t_stack *st)
{
	int	i;
	int	big;
	int	index;

	i = 0;
	big = INT32_MIN;
	while (i < st->len - st->index)
	{
		if (st->b[i] > big)
		{
			index = i;
			big = st->b[i];
		}
		i++;
	}
	return (index);
}

void	algo_v2_0_2(t_stack *st, int n, int t)
{
	int	m;

	if (n == st->min)
		m = st->p1;
	else if (n == st->p2)
		m = st->p3;
	else if (n == st->p4)
		m = st->mid;
	else if (n == st->p6)
		m = st->p7;
	else if (n == st->p8)
		m = st->p9;
	if ((st->b[0] >= st->o[n] && st->b[0] < st->o[m]))
	{
		if (st->a[0] >= st->o[n] && st->a[0] < st->o[t])
			rotate_b(st, 0);
		else
			ra_rb(st, 0);
	}
}

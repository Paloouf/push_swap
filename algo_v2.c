/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:10:33 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/24 14:30:51 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	on_fait_des_essais(t_stack *st, int n, int m)
{
	int	j;
	int	i;

	j = -1;
	i = 0;
	while (j < 0 && i < st->index)
	{
		if ((st->a[i] >= st->o[n] && st->a[i] < st->o[m]))
			j = i;
		i++;
	}
	if (j >= 0)
	{
		while (j >= 1)
		{
			rotate_a(st, 0);
			j--;
		}
		push_b(st);
	}
	if (st->index < st->len - 1)
		algo_v2_0_2(st, n, m);
}

int	is_p_in_b(t_stack *st, int n, int m)
{
	int	check;
	int	i;

	i = 0;
	check = 0;
	if (st->index < st->len)
	{
		while (i < st->len - st->index)
		{	
			if ((st->b[i] >= st->o[n] && st->b[i] < st->o[m]))
				check++;
			i++;
		}
		if (check == (m - n))
			return (1);
	}
	return (0);
}

int	is_p_in_a_sorted(t_stack *st, int n, int m)
{
	int	check;
	int	i;

	i = 0;
	check = 0;
	if (st->index <= st->len && st->index > 0)
	{
		while (i < st->index)
		{
			if ((st->a[i] >= st->o[n] && st->a[i] < st->o[m]))
				check++;
			i++;
		}
		if (check == (m - n))
			return (1);
	}
	return (0);
}

void	algo_v2_0_1(t_stack *st)
{
	if (st->len < 10)
	{
		while (!is_sorted(st))
			algo_one(st);
		return ;
	}
	while (!is_p_in_b(st, st->min, st->p2))
		on_fait_des_essais(st, st->min, st->p2);
	while (!is_p_in_b(st, st->p2, st->p4))
		on_fait_des_essais(st, st->p2, st->p4);
	while (!is_p_in_b(st, st->p4, st->p6))
		on_fait_des_essais(st, st->p4, st->p6);
	while (!is_p_in_b(st, st->p6, st->p8))
		on_fait_des_essais(st, st->p6, st->p8);
	while (!is_p_in_b(st, st->p8, st->max))
		on_fait_des_essais(st, st->p8, st->max);
	algo_v2_1_1(st);
	while (st->a[0] != st->o[0])
		r_rotate_a(st, 0);
}

void	algo_v2_1_1(t_stack *st)
{
	now_we_sort(st, st->p9, st->max);
	now_we_sort_more(st, st->b[find_big(st)],
		st->b[find_small(st, st->p8, st->p9)]);
	now_we_sort(st, st->p8, st->p9);
	now_we_sort_better(st);
	now_we_sort(st, st->p7, st->p8);
	now_we_sort_more(st, st->b[find_big(st)],
		st->b[find_small(st, st->p6, st->p7)]);
	now_we_sort(st, st->p6, st->p7);
	now_we_sort_better(st);
	now_we_sort(st, st->mid, st->p6);
	now_we_sort_more(st, st->b[find_big(st)],
		st->b[find_small(st, st->p4, st->mid)]);
	now_we_sort(st, st->p4, st->mid);
	now_we_sort_better(st);
	now_we_sort(st, st->p3, st->p4);
	now_we_sort_more(st, st->b[find_big(st)],
		st->b[find_small(st, st->p2, st->p3)]);
	now_we_sort(st, st->p2, st->p3);
	now_we_sort_better(st);
	now_we_sort(st, st->p1, st->p2);
	now_we_sort_more(st, st->b[find_big(st)],
		st->b[find_small(st, 0, st->p1)]);
	now_we_sort(st, 0, st->p1);
}

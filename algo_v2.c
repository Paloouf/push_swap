/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:10:33 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/20 16:49:41 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	on_fait_des_essais(t_stack *st, int n, int m)
{
	int	j;
	int	i;

	j = -1;
	i = 0;
	if (st->len <= 10)
	{
		algo_one(st);
	}
	while (j < 0 && st->a[i])
	{
		if ((st->a[i] >= st->o[n] && st->a[i] < st->o[m]))
			j = i;
		i++;
	}
	if (j >= 0)
	{
		while(j >= 1)
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
		while (st->b[i])
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
	if (st->index <= st->len)
	{
		while (st->a[i])
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
	now_we_sort(st, st->p9, st->max);
	now_we_sort_more(st, st->b[find_big(st)], st->b[find_small(st, st->p8, st->p9)]);
	now_we_sort(st, st->p8, st->p9);
	now_we_sort_better(st);
	now_we_sort(st, st->p7, st->p8);
	now_we_sort_more(st, st->b[find_big(st)], st->b[find_small(st, st->p6, st->p7)]);
	now_we_sort(st, st->p6, st->p7);
	now_we_sort_better(st);
	now_we_sort(st, st->mid, st->p6);
	now_we_sort_more(st, st->b[find_big(st)], st->b[find_small(st, st->p4, st->mid)]);
	now_we_sort(st, st->p4, st->mid);
	now_we_sort_better(st);
	now_we_sort(st, st->p3, st->p4);
	now_we_sort_more(st, st->b[find_big(st)], st->b[find_small(st, st->p2, st->p3)]);
	now_we_sort(st, st->p2, st->p3);
	now_we_sort_better(st);
	now_we_sort(st, st->p1, st->p2);
	now_we_sort_more(st, st->b[find_big(st)], st->b[find_small(st, 0, st->p1)]);
	now_we_sort(st, 0, st->p1);
	while (st->a[0] != st->o[0])
		r_rotate_a(st, 0);
}

void	now_we_sort(t_stack *st, int n, int m)
{
	int	big;
	int	small;
	int	i;

	i = 0;
	while (!is_p_in_a_sorted(st, n, m))
	{
		if (st->b[i] >= st->o[n] && st->b[i] < st->o[m])
		{
			big = find_big(st);
			small = find_small(st, n, m);
			if (big < small)
			{
				if (big < ((st->len - st->index -1) /2))
				{
					while (big > 0)
					{
						rotate_b(st, 0);
						big--;
					}
					push_a(st);
				}
				else
				{
					while (big <= (st->len - st->index -1))
					{
						r_rotate_b(st, 0);
						big++;
					}
					push_a(st);
				}
			}
			else
			{
				if (small < ((st->len - st->index -1) /2))
				{
					while (small > 0)
					{
						rotate_b(st, 0);
						small--;
					}
					push_a(st);
					if (st->index != st->len)
						rotate_a(st, 0);
				}
				else
				{
					while (small <= (st->len - st->index -1))
					{
						r_rotate_b(st, 0);
						small++;
					}
					push_a(st);
					if (st->index != st->len)
						rotate_a(st, 0);
				}
			}
		}
		i++;
	}
}

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
			r_ra_rb(st);
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
	while(st->b[i])
	{
		if ((st->b[i] >= st->o[n] && st->b[i] < st->o[m]) && st->b[i]< small)
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
	while(st->b[i])
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
		if (st->a[0]  >= st->o[n] && st->a[0] < st->o[t])
			rotate_b(st, 0);
		else
			ra_rb(st);
	}
}
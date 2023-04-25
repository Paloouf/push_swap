/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:10:20 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/25 13:10:38 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	now_we_sort(t_stack *st, int n, int m)
{
	int	big;
	int	small;

	while (!is_p_in_a_sorted(st, n, m))
	{
		if (st->len - st->index > 0)
		{
			big = find_big(st);
			small = find_small(st, n, m);
			now_we_sort_2(st, big, small);
		}
	}
}

void	now_we_sort_2(t_stack *st, int big, int small)
{
	if (big < small)
	{
		if (big < ((st->len - st->index -1) / 2))
		{
			while (big > 0)
			{
				rotate_b(st, 0);
				big--;
			}
			push_a(st, 0);
		}
		else
		{
			while (big <= (st->len - st->index -1))
			{
				r_rotate_b(st, 0);
				big++;
			}
			push_a(st, 0);
		}
	}
	else
		now_we_sort_3(st, small);
}

void	now_we_sort_3(t_stack *st, int small)
{
	if (small < ((st->len - st->index -1) / 2))
	{
		while (small > 0)
		{
			rotate_b(st, 0);
			small--;
		}
		push_a(st, 0);
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
		push_a(st, 0);
		if (st->index != st->len)
			rotate_a(st, 0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:45:50 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/21 13:01:26 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refill_a(t_stack *st)
{
	while (st->index != st->len)
	{
		push_a(st);
		if (st->a[1] < st->a[0])
			swap_a(st, 0);
	}
	if (st->a[st->len -1] < st->a[st->len -2])
	{
		algo_three(st);
	}
}

void	algo_one(t_stack *st)
{
	if (is_sorted(st) == 1 && st->index == st->len)
		return ;
	if (st->index > 1)
	{
		if (st->a[0] < st->a[1])
		{
			if (st->a[0] < st->a[st->index - 1])
			{
				push_b(st);
			}
			else if (st->a[0] >= st->a[st->index - 1])
				r_rotate_a(st, 0);
		}
		else
			swap_a(st, 0);
		if (st->index < st->len - 1)
			algo_two(st);
		if (is_sorted(st) == 1 && st->index == st->len - 1)
			push_a(st);
	}
}

void	algo_two(t_stack *st)
{
	if (st->b[0] > st->b[1])
	{
		if ((st->b[0] < st->b[st->len - st->index - 1])
			&& (st->len - st->index > 2))
			r_rotate_b(st, 0);
	}
	else
		swap_b(st, 0);
	if (st->index == 2)
		refill_a(st);
}

//useful for last two numbers needed to be swapped
void	algo_three(t_stack *st)
{
	r_rotate_a(st, 0);
	r_rotate_a(st, 0);
	swap_a(st, 0);
	rotate_a(st, 0);
	rotate_a(st, 0);
	return ;
}

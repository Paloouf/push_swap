/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:37:13 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/25 13:10:54 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_nul(t_stack *st)
{
	if (!is_a_sorted(st))
	{
		if (st->a[0] < st->a[1])
		{
			if (st->a[0] < st->a[st->index - 1])
			{
				r_rotate_a(st, 0);
				swap_a(st, 0);
			}
			else
				r_rotate_a(st, 0);
		}
		else
		{
			if (st->a[0] > st->a[2] && st->a[1] > st->a[2])
			{
				swap_a(st, 0);
				r_rotate_a(st, 0);
			}
			else if (st->a[0] < st->a[2] && st->a[1] < st->a[2])
				swap_a(st, 0);
			else
				rotate_a(st, 0);
		}
	}
}

void	algo_nul_reborn(t_stack *st)
{
	while (st->a[0] != st->o[0] && st->a[0] != st->o[1])
		rotate_a(st, 0);
	push_b(st, 0);
	while (st->a[0] != st->o[0] && st->a[0] != st->o[1])
		rotate_a(st, 0);
	push_b(st, 0);
	algo_nul(st);
	if (st->b[0] < st->b[1])
		swap_b(st, 0);
	push_a(st, 0);
	push_a(st, 0);
	return ;
}

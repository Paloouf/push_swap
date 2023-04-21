/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:52:27 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/21 13:15:12 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_stack *st, int flag)
{
	int	i;
	int	temp;

	temp = st->a[st->index - 1];
	i = 0;
	while (i < st->index - 1)
	{
		st->a[st->index - (i + 1)] = st->a[st->index - (i + 2)];
		i++;
	}
	st->a[0] = temp;
	if (flag != 1)
		write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack *st, int flag)
{
	int	i;
	int	temp;

	temp = st->b[st->len - st->index - 1];
	i = 0;
	while (i < (st->len - st->index - 1))
	{
		st->b[st->len - st->index - (i + 1)] = st->b[st->len
			- st->index - (i + 2)];
		i++;
	}
	st->b[0] = temp;
	if (flag != 1)
		write(1, "rrb\n", 4);
}

void	r_ra_rb(t_stack *st)
{
	r_rotate_a(st, 1);
	r_rotate_b(st, 1);
	write(1, "rrr\n", 4);
}

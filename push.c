/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:53:19 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/25 13:08:39 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *st, int flag)
{
	int	i;
	int	temp;

	temp = st->b[0];
	i = 0;
	if (st->index < st->len)
	{
		while (i < st->len - 1)
		{
			st->a[st->len - (i + 1)] = st->a[st->len - (i + 2)];
			st->b[i] = st->b[i + 1];
			i++;
		}
		st->b[st->len - st->index - 1] = 0;
		st->index++;
		st->a[0] = temp;
		if (flag != 1)
			write(1, "pa\n", 3);
	}
}

void	push_b(t_stack *st, int flag)
{
	int	i;
	int	temp;

	temp = st->a[0];
	i = 0;
	if (st->index > 0)
	{
		while (i < st->len - 1)
		{
			st->b[st->len - (i + 1)] = st->b[st->len - (i + 2)];
			st->a[i] = st->a[i + 1];
			i++;
		}
		st->a[st->index - 1] = 0;
		st->index--;
		st->b[0] = temp;
		if (flag != 1)
			write(1, "pb\n", 3);
	}
}

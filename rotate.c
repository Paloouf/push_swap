/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:10:46 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/04 15:44:04 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *st, int flag)
{
	int	i;
	int	temp;

	temp = st->a[0];
	i = 0;
	while (i < st->index - 1)
	{
		st->a[i] = st->a[i + 1];
		i++;
	}
	st->a[st->index - 1] = temp;
	if (flag != 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *st, int flag)
{
	int	i;
	int	temp;

	temp = st->b[0];
	i = 0;
	while (i < (st->len - st->index - 1))
	{
		st->b[i] = st->b[i + 1];
		i++;
	}
	st->b[(st->len - st->index) - 1] = temp;
	if (flag != 1)
		write(1, "rb\n", 3);
}

void	ra_rb(t_stack *st)
{
	rotate_a(st, 1);
	rotate_b(st, 1);
	write(1, "rr\n", 3);
}
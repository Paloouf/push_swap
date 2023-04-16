/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:45:26 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/04 15:44:06 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *st, int flag)
{
	int temp;

	temp = st->a[0];
	st->a[0] = st->a[1];
	st->a[1] = temp;
	if (flag != 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *st, int flag)
{
	int temp;

	temp = st->b[0];
	st->b[0] = st->b[1];
	st->b[1] = temp;
	if (flag != 1)
		write(1, "sb\n", 3);
}

void	sswap(t_stack *st)
{
	int	flag;

	flag = 1;
	swap_a(st, flag);
	swap_b(st, flag);
	write(1, "ss\n", 3);
}



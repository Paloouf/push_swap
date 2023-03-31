/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:45:26 by ltressen          #+#    #+#             */
/*   Updated: 2023/03/31 09:51:42 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stacks, int flag)
{
	int temp;

	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	if (flag != 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stacks, int flag)
{
	int temp;

	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
	if (flag != 1)
		write(1, "sb\n", 3);
}

void	sswap(t_stack *stacks)
{
	int	flag;

	flag = 1;
	swap_a(stacks, flag);
	swap_b(stacks, flag);
	write(1, "ss\n", 3);
}



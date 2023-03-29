/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:45:26 by ltressen          #+#    #+#             */
/*   Updated: 2023/03/29 13:37:36 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stacks)
{
	int temp;

	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
}

void	swap_b(t_stack *stacks)
{
	int temp;

	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
}

void	sswap(t_stack *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}



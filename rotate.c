/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:10:46 by ltressen          #+#    #+#             */
/*   Updated: 2023/03/30 12:57:49 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stacks)
{
	int	i;
	int	temp;

	temp = stacks->a[0];
	i = 0;
	while (i < stacks->index - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->index - 1] = temp;
}

void	rotate_b(t_stack *stacks)
{
	int	i;
	int	temp;

	temp = stacks->b[0];
	i = 0;
	while (i < (stacks->len - stacks->index - 1))
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[(stacks->len - stacks->index) - 1] = temp;
}

void	ra_rb(t_stack *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
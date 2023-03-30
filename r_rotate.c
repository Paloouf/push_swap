/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:52:27 by ltressen          #+#    #+#             */
/*   Updated: 2023/03/30 12:43:54 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_stack *stacks)
{
	int	i;
	int	temp;

	temp = stacks->a[stacks->index - 1];
	i = 0;
	while (i < stacks->index - 1)
	{
		stacks->a[stacks->index - (i + 1)] = stacks->a[stacks->index - (i + 2)];
		i++;
	}
	stacks->a[0] = temp;
}

void	r_rotate_b(t_stack *stacks)
{
	int	i;
	int	temp;

	temp = stacks->b[stacks->len - stacks->index - 1];
	i = 0;
	while (i < (stacks->len - stacks->index - 1))
	{
		stacks->b[stacks->len - stacks->index - (i + 1)] = stacks->b[stacks->len
			- stacks->index - (i + 2)];
		i++;
	}
	stacks->b[0] = temp;
}

void	r_ra_rb(t_stack *stacks)
{
	r_rotate_a(stacks);
	r_rotate_b(stacks);
}
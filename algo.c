/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:45:50 by ltressen          #+#    #+#             */
/*   Updated: 2023/03/30 14:03:24 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stacks)
{
	int	i;

	i = 0;
	while ((i + 1) < stacks->len)
	{
		if (stacks->a[i] < stacks->a[i + 1])
			i++;	
		else
			return (0);
	}
	return (1);
}
void	algo_one(t_stack *stacks)
{
		//compare 1st, 2nd and last ints and decide which op is best
		if (stacks->a[0] < stacks->a[1])
		{
			if (stacks->a[0] < stacks->a[stacks->index - 1])
			{
				push_b(stacks);
			}
			else
				r_rotate_a(stacks);
		}
		else
			swap_a(stacks);
}
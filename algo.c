/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:45:50 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/03 14:39:42 by ltressen         ###   ########.fr       */
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

int	is_b_sorted(t_stack *stacks)
{
	int	i;

	i = 0;
	while ((i + 1) < (stacks->len - stacks->index))
	{
		if (stacks->b[i] > stacks->b[i + 1])
			i++;	
		else
			return (0);
	}
	return (1);
}

void	refill_a(t_stack *stacks)
{
	while (stacks->index != stacks->len)
	{
		push_a(stacks);
		if (stacks->a[1] < stacks->a[0])
			swap_a(stacks, 0);
	}
	if (stacks->a[stacks->len -1] < stacks->a[stacks->len -2])
	{
		algo_three(stacks);
	}
}
void	algo_one(t_stack *stacks)
{
	//compare 1st, 2nd and last ints and decide which op is best
	if (is_sorted(stacks) == 1 && stacks->index == stacks->len)
		return ;
	if (stacks->index > 1)
	{
		if (stacks->a[0] < stacks->a[1])
		{
			if (stacks->a[0] < stacks->a[stacks->index - 1])
			{
				push_b(stacks);
			}
			else
				r_rotate_a(stacks, 0);
		}
		else
			swap_a(stacks, 0);
		if (stacks->index < stacks->len - 1)
			algo_two(stacks);
		if (is_sorted(stacks) == 1 && stacks->index == stacks->len - 1)
			push_a(stacks);
	}
}

void	algo_two(t_stack *stacks)
{
	if (stacks->b[0] > stacks->b[1])
	{
		if ((stacks->b[0] < stacks->b[stacks->len - stacks->index - 1]) && (stacks->len - stacks->index > 2))
			r_rotate_b(stacks, 0);
	}
	else
		swap_b(stacks, 0);
	if (stacks->index == 2)
		refill_a(stacks);
}

//useful for last two numbers needed to be swapped
void	algo_three(t_stack *stacks)
{
	r_rotate_a(stacks, 0);
	r_rotate_a(stacks, 0);
	swap_a(stacks, 0);
	rotate_a(stacks, 0);
	rotate_a(stacks, 0);
	return ;
}
//is_b_sorted(stacks) == 1 && 
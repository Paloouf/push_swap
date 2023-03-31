/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:53:19 by ltressen          #+#    #+#             */
/*   Updated: 2023/03/31 13:35:45 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stacks)
{
	int	i;
	int	temp;

	temp = stacks->b[0];
	i = 0;
	if (stacks->index < stacks->len)
	{
		while (i < stacks->len - 1)
		{
			stacks->a[stacks->len - (i + 1)] = stacks->a[stacks->len - (i + 2)];
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->b[stacks->len - stacks->index - 1] = 0;
		stacks->index++;
		stacks->a[0] = temp;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_stack *stacks)
{
	int	i;
	int	temp;

	temp = stacks->a[0];
	i = 0;
	if (stacks->index > 0)
	{
		while (i < stacks->len - 1)
		{
			stacks->b[stacks->len - (i + 1)] = stacks->b[stacks->len - (i + 2)];
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a[stacks->index - 1] = 0;
		stacks->index--;
		stacks->b[0] = temp;
		write(1, "pb\n", 3);
	}

}


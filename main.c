/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:30:18 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/03 15:36:35 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int i;

	if (!make_stacks(&stacks, argc, argv))
		return (0);
	i = 0;
	/*swap_a(&stacks, 0);
	push_b(&stacks);
	swap_a(&stacks, 0);
	push_b(&stacks);
	swap_b(&stacks, 0);
	push_b(&stacks);
	push_b(&stacks);
	push_a(&stacks);
	//push_a(&stacks);
	//push_a(&stacks);
	//push_a(&stacks);
	//swap_a(&stacks, 0);*/
	while(is_sorted(&stacks) != 1)
	{
		algo_one(&stacks);
		i++;
	}
	i = 0;
	while(i < stacks.len)
	{
		printf("a :%d \t b :%d\n", stacks.a[i], stacks.b[i]);
		i++;
	}
	//free(stacks->a);
	//free(stacks->b);
	return (0);

}
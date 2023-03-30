/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:30:18 by ltressen          #+#    #+#             */
/*   Updated: 2023/03/30 14:56:31 by ltressen         ###   ########.fr       */
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
	push_b(&stacks);
	push_b(&stacks);
	push_b(&stacks);
	r_rotate_b(&stacks);
	while(i < stacks.len)
	{
		printf("a :%d \t b :%d\n", stacks.a[i], stacks.b[i]);
		i++;
	}
	//free(stacks->a);
	//free(stacks->b);
	return (0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:30:18 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/16 13:58:38 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	st;
	int i;

	if (!make_stacks(&st, argc, argv))
		return (0);
	i = 0;
	while(i < 50)
	{
		algo_v2(&st);
		i++;
	}
	i = 0;
	printf("\n");
	while(i < st.len)
	{
		printf("a :%d \t b :%d \t o: %d \t 90%% of o :%d\n", st.a[i], st.b[i], st.o[i], st.o[(st.len/10) * 10 - 1]);
		i++;
	}
	free(st.a);
	free(st.b);
	free(st.o);
	return (0);

}
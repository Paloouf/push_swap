/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:30:18 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/24 12:13:28 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	st;

	if (argc > 3)
	{
		if (!make_stacks(&st, argc, argv))
			return (0);
		algo_v2_0_1(&st);
		free(st.a);
		free(st.b);
		free(st.o);
	}
	else
		write(1, "Error : Not enough arguments\n", 6);
	return (0);
}

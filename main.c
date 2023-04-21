/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:30:18 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/21 13:14:38 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	st;

	if (!make_stacks(&st, argc, argv))
		return (0);
	algo_v2_0_1(&st);
	free(st.a);
	free(st.b);
	free(st.o);
	return (0);
}

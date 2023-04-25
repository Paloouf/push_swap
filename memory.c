/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:29:51 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/25 14:24:23 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_index(t_stack *st)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	st->o = (int *)malloc(sizeof(int) * st->len);
	if (!st->o)
		exit(EXIT_FAILURE);
	while (i < st->index)
	{
		j = 0;
		index = 0;
		while (j < st->index)
			if (st->a[i] > st->a[j++])
				index++;
		st->o[index] = st->a[i];
		i++;
	}
	get_values(st);
	return (1);
}

void	get_values(t_stack *st)
{
	st->min = 0;
	st->p1 = st->len / 10;
	st->p2 = (st->len / 10) * 2;
	st->p3 = (st->len / 10) * 3;
	st->p4 = (st->len / 10) * 4;
	st->mid = (st->len / 2);
	st->p6 = (st->len / 10) * 6;
	st->p7 = (st->len / 10) * 7;
	st->p8 = (st->len / 10) * 8;
	st->p9 = (st->len / 10) * 9;
	st->max = st->len - 1;
}

int	make_stacks(t_stack *st, int argc, char **argv)
{
	if (argc == 2)
		fill_a_split(st, argv);
	else
	{
		st->len = argc -1;
		st->a = (int *)malloc(sizeof(int *) * argc - 1);
		st->b = ft_calloc((argc - 1), sizeof(int *));
		fill_a(st, argv);
	}
	st->index = st->len;
	if (!st->a || !st->b)
		exit(EXIT_FAILURE);
	else
		check_args(st);
	make_index(st);
	return (1);
}

void	check_args(t_stack *st)
{
	int	i;
	int	j;

	i = 0;
	while (i < st->len - 1)
	{
		j = i + 1;
		while (j < st->len)
		{
			if (st->a[i] == st->a[j])
			{
				write(1, "Error\n", 6);
				panic_free(st);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	panic_free(t_stack *st)
{
	free(st->a);
	free(st->b);
}

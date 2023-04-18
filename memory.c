/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:29:51 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/18 12:40:47 by ltressen         ###   ########.fr       */
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
	st->o = (int *)malloc(sizeof(int) * st->len + 1);
	if (!st->o)
		exit(EXIT_FAILURE);
	while (st->a[i])
	{
		j = 0;
		index = 0;
		while(st->a[j])
		{
			if (st->a[i] > st->a[j])
				index++;
			j++;
		}
		st->o[index] = st->a[i];
		i++;
	}
	st->o[st->len] = '\0';
	return (1);
}

int	make_stacks(t_stack *st, int argc, char **argv)
{
	char	**splitted;
	int	i;

	i = 0;
	if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		while (splitted[i])
			i++;
		st->len = i;
		st->a = malloc(sizeof(int *) * i);
		st->b = ft_calloc(i, sizeof(int *));
		fill_a_split(st, splitted);
	}
	else
	{
		st->len = argc -1;
		st->a = malloc(sizeof(int *) * argc - 1);
		st->b = ft_calloc((argc - 1), sizeof(int *));
		fill_a(st, argv);
	}
	st->index = st->len;
	if (!st->a || !st->b)
		exit(EXIT_FAILURE);
	make_index(st);
	return (1);
}

void	fill_a(t_stack *st, char **argv)
{
	int	i;

	i = 0;
	while (argv[i +1] != NULL)
	{
		st->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	fill_a_split(t_stack *st, char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		st->a[i] = ft_atoi(splitted[i]);
		i++;
	}
}

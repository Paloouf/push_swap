/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:29:51 by ltressen          #+#    #+#             */
/*   Updated: 2023/03/30 12:42:14 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_stacks(t_stack *stacks, int argc, char **argv)
{
	char	**splitted;
	int	i;

	i = 0;
	if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		while (splitted[i])
			i++;
		stacks->len = i;
		stacks->a = malloc(sizeof(int *) * i);
		stacks->b = ft_calloc(i, sizeof(int *));
		fill_a_split(stacks, splitted);
	}
	else
	{
		stacks->len = argc -1;
		stacks->a = malloc(sizeof(int *) * argc - 1);
		stacks->b = ft_calloc((argc - 1), sizeof(int *));
		fill_a(stacks, argv);
	}
	stacks->index = stacks->len;
	if (!stacks->a || !stacks->b)
		exit(EXIT_FAILURE);
	return (1);
}

void	fill_a(t_stack *stacks, char **argv)
{
	int	i;

	i = 0;
	while (argv[i +1] != NULL)
	{
		stacks->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	fill_a_split(t_stack *stacks, char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		stacks->a[i] = ft_atoi(splitted[i]);
		i++;
	}
}

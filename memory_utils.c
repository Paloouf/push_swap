/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:36:28 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/24 15:46:06 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(t_stack *st, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i +1] != NULL)
	{
		j = 0;
		while (argv[i + 1][j])
		{
			if ((argv[i + 1][j] >= '0' && argv[i + 1][j] <= '9')
			|| argv[i +1][j] == '-')
				j++;
			else
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
		}
		st->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	fill_a_split(t_stack *st, char **argv)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(argv[1], ' ');
	while (splitted[i])
		i++;
	st->len = i;
	st->a = malloc(sizeof(int *) * i);
	st->b = ft_calloc(i, sizeof(int *));
	while (splitted[i])
	{
		st->a[i] = ft_atoi(splitted[i]);
		i++;
	}
}

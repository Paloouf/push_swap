/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:36:28 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/25 10:46:51 by ltressen         ###   ########.fr       */
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
			if (((argv[i + 1][j] >= '0' && argv[i + 1][j] <= '9')
			|| argv[i +1][j] == '-') && check_intmax(argv))
				j++;
			else
			{
				write(1, "Error\n", 6);
				panic_free(st);
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
	fill_a_split2(st, splitted);
}

void	fill_a_split2(t_stack *st, char **splitted)
{
	int	i;
	int	j;

	i = 0;
	while (splitted[i])
	{
		j = 0;
		while (splitted[i][j])
		{
			if (((splitted[i][j] >= '0' && splitted[i][j] <= '9')
			|| splitted[i][j] == '-') && check_intmax(splitted))
				j++;
			else
			{
				write(1, "Error\n", 6);
				panic_free(st);
				exit(EXIT_FAILURE);
			}
		}
		st->a[i] = ft_atoi(splitted[i]);
		i++;
	}
	free_split(splitted);
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

int	check_intmax(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{	
		if (ft_strlen(av[i]) > 11)
			return (0);
		else if (ft_strlen(av[i]) == 11)
		{
			if (ft_strncmp(av[i], "-2147483648", 11) > 0)
				return (0);
		}
		else if (ft_strlen(av[i]) == 10
			&& ft_strncmp(av[i], "2147483647", 10) > 0)
			return (0);
		i++;
	}
	return (1);
}

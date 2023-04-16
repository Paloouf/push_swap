/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:10:33 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/16 16:07:07 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	algo_v2(t_stack *st)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	min = 0;
	max = 0;
	while(st->a[i])
	{
		if (st->a[i] < min)
			min = st->a[i];
		if (st->a[i] > max)
			max = st->a[i];
		i++;
	}
	st->max = max;
	st->min = min;
	algo_v2_0_1(st);
	//premier 20% =  if st->a[i] <= st->o[st->len/5] // deuxieme 20% = st->o[(st->len/5)*2] // 3eme 20% = st->o[(st->len/5)*3]
}

int	best_choice(t_stack *st, int i, int n)
{
	int	j;

	j = i;
	//printf("LOL");
	//printf("a[i] : %d, o[len/10] : %d, o[len/10 * n + 1] : %d", st->a[i], st->o[(st->len/10 * n)], st->o[(st->len/10) * (n + 1)]);
	//n c'est la partition, pour n = 1, on veut la partition de 10 a 20%, comment l'utiliser ici
	//si i inferieur a 50% de la len totale quel move est le plus opti
	if (st->len < 10)
	{
		algo_one(st);
	}
	if (st->a[i] >= st->o[(st->len/10 * n) - 1] && st->a[i] <= st->o[(st->len/10) * (n + 1) - 1])
	{
		if (i <= st->len/2)
		{
			//tant qu'on est pas revenu au debut
			while(j >= 1)
			{
				rotate_a(st, 0);
				j--;
			}
		}
		else
		{
			//tant qu'on est pas arrive a la fin
			while (j < st->len - 1)
			{
				r_rotate_a(st, 0);
				j++;
			}
		}
		//printf("WAAA");
		push_b(st);
		i = -1;
		if (st->index < st->len - 1)
			algo_v2_0_2(st);
		return (1);
	}
	else
		return (0);
}

//is the partition in b
int	is_p_in_b(t_stack *st, int n)
{
	int	j;
	static int	check = 0;

	j = 0;
	if (st->index < st->len - 1)
	{
		while (st->b[j])
		{
			if (st->b[j] >= st->o[(st->len/10 * n)] && st->b[j]  < st->o[(st->len/10) * (n + 1) - 1])
				check++;
			j++;
		}
	}
	printf("check : %d, len/10 : %d", check, (st->len/10 * (n+1)));
	if (check == ((st->len/ 10) * (n+1)))
		return (1);
	else
		return (0);
}

//pre-tri 1/10 dans l'algo de tri pour push dans b
void	algo_v2_0_1(t_stack *st)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (st->a[i])
	{
		while (n < 10)
		{
			while (is_p_in_b(st, n) != 1)
			{
				if (best_choice(st, i, n) == 1)
					i = -1;
				i++;
			}
			n++;
		}
		
	}		
}

void	algo_v2_0_2(t_stack *st)
{
	if (st->b[0] > st->b[1])
	{
		if ((st->b[0] < st->b[st->len - st->index - 1]) && (st->len - st->index > 2))
			r_rotate_b(st, 0);
	}
	else
		swap_b(st, 0);
}
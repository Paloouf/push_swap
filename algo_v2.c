/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:10:33 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/18 15:46:00 by ltressen         ###   ########.fr       */
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

void	best_choice(t_stack *st, int i, float n, float m)
{
	int	j;

	j = i;
	if (st->len <= 10)
	{
		algo_one(st);
	}
	if ((st->a[i] >= st->o[(int)(st->len * n)] && st->a[i] < st->o[(int)(st->len * (n+0.1))]) || (st->a[i] >= st->o[(int)(st->len * m)] && st->a[i] <= st->o[(int)(st->len * (m+0.1) - 1)]))
	{
		if (i <= st->index/2)
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
			while (j <= st->index - 1)
			{
				r_rotate_a(st, 0);
				j++;
			}
		}
		ft_printf("WAAA %d \t", st->index);
		push_b(st);
		if (st->index < st->len - 1)
			algo_v2_0_2(st, n);
	}
}


int	is_p_in_b(t_stack *st, float n, float m)
{
	int	check;
	int	i;

	i = 0;
	check = 0;
	if (st->index < st->len)
	{
		//ft_printf("ICI");
		while (st->b[i])
		{
			
			if ((st->b[i] >= st->o[(int)(st->len * n)] && st->b[i] < st->o[(int)(st->len * (n+0.1))]) || (st->b[i] >= st->o[(int)(st->len * m)] && st->b[i] <= st->o[(int)(st->len * (m+0.1)) - 1]))
				check++;
			i++;
		}
		//ft_printf("LA");
		if (check == ((int)(st->len * 0.2)))
			return (1);
	}
	return (0);
}

void	closest_index(t_stack *st, float n, float m)
{
	int i;
	int j;
	int index_start;
	int index_end;

	j = st->index - 1;
	i = -1;
	index_start = -1;
	index_end = -1;
	//printf("n : %f , m : %f \n", n,m);
	while (index_start < 0 && i < st->index)
	{
		i++;
		if ((st->a[i] >= st->o[(int)(st->len * n)] && st->a[i] < st->o[(int)(st->len * (n+0.1))]) || (st->a[i] >= st->o[(int)(st->len * m)] && st->a[i] <= st->o[(int)(st->len * (m+0.1) - 1)]))
			index_start = i;	
	}
	//printf("%d , %d", i, j);
	while (index_end < 0 && j > -1)
	{
		if ((st->a[j] >= st->o[(int)(st->len * n)] && st->a[j] < st->o[(int)(st->len * (n+0.1))]) || (st->a[j] >= st->o[(int)(st->len * m)] && st->a[j] <= st->o[(int)(st->len * (m+0.1) - 1)]))
			index_end = st->index - j;
		j--;
	}
	if (index_start > index_end)
	{
		//le meilleur move est rra
		best_choice(st, j + 1, n, m);
	}
	else
		best_choice(st, i, n, m);
}

//pre-tri 1/10 dans l'algo de tri pour push dans b
void	algo_v2_0_1(t_stack *st)
{
	float	n;
	float	m;

	
	n = 0;
	m = n + 0.1;
	while (m < 1)
	{
		//ft_printf("n: %d \t m: %d \n", (n * 10), (m * 10));
		while (!is_p_in_b(st, n, m))
		{
			closest_index(st, n, m);
		}
		//ft_printf("bonjour \n");
		n += 0.2;
		m += 0.2;
	}		
}

void	algo_v2_0_2(t_stack *st, float n)
{
	//printf("LEBUG");
	if ((st->b[0] >= st->o[(int)(st->len * n)] && st->b[0] < st->o[(int)((st->len) * (n+0.1))]))
		rotate_b(st, 0);
	//printf("LEBUG2");

}
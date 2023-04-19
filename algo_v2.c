/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:10:33 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/19 15:53:35 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	best_choice(t_stack *st, int i, float n, float m)
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
		push_b(st);
		if (st->index < st->len - 1)
			algo_v2_0_2(st, n);
	}
}*/



void	on_fait_des_essais(t_stack *st, int n, int m)
{
	int	j;
	int	i;

	j = -1;
	i = 0;
	if (st->len <= 10)
	{
		algo_one(st);
	}
	while (j < 0 && st->a[i])
	{
		if ((st->a[i] >= st->o[n] && st->a[i] < st->o[m]))
			j = i;
		i++;
	}
	//tant qu'on est pas revenu au debut
	if (j >= 0)
	{
		while(j >= 1)
		{
			rotate_a(st, 0);
			j--;
			
		}
		push_b(st);
	}
	if (st->index < st->len - 1)
		algo_v2_0_2(st, n);

}


/*void	closest_index(t_stack *st, float n, float m)
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
		{
			index_start = i;	
			ft_printf("%d \t", index_start);
		}
	}
	ft_printf("%d , %d ", i, j);
	while (index_end < 0 && j > 0)
	{
		if ((st->a[j] >= st->o[(int)(st->len * n)] && st->a[j] < st->o[(int)(st->len * (n+0.1))]) || (st->a[j] >= st->o[(int)(st->len * m)] && st->a[j] <= st->o[(int)(st->len * (m+0.1) - 1)]))
		{
			index_end = st->index - j;
			ft_printf("%d \t", index_end);
		}
		j--;
	}
	if (index_start > index_end)
	{
		//le meilleur move est rra
		best_choice(st, j + 1, n, m);
	}
	else
		best_choice(st, i, n, m);
}*/

int	is_p_in_b(t_stack *st, int n, int m)
{
	int	check;
	int	i;

	i = 0;
	check = 0;
	if (st->index < st->len)
	{
		while (st->b[i])
		{
			
			if ((st->b[i] >= st->o[n] && st->b[i] < st->o[m]))
				check++;
			i++;
		}
		if (check == (m - n))
			return (1);
	}
	return (0);
}

int	is_p_in_a_sorted(t_stack *st, int n, int m)
{
	int	check;
	int	i;

	i = 0;
	check = 0;
	if (st->index < st->len)
	{
		while (st->a[i])
		{
			
			if ((st->a[i] >= st->o[n] && st->a[i] < st->o[m]))
				check++;
			i++;
		}
		if (check == (m - n))
			return (1);
	}
	return (0);
}

//pre-tri 1/10 dans l'algo de tri pour push dans b
void	algo_v2_0_1(t_stack *st)
{
	while (!is_p_in_b(st, st->min, st->p2))
	{
		//closest_index(st, n, m);
		on_fait_des_essais(st, st->min, st->p2);
	}	
	while (!is_p_in_b(st, st->p2, st->p4))
	{
		//closest_index(st, n, m);
		on_fait_des_essais(st, st->p2, st->p4);
	}	
	while (!is_p_in_b(st, st->p4, st->p6))
	{
		//closest_index(st, n, m);
		on_fait_des_essais(st, st->p4, st->p6);
	}
	while (!is_p_in_b(st, st->p6, st->p8))
	{
		//closest_index(st, n, m);
		on_fait_des_essais(st, st->p6, st->p8);
	}	
	while (!is_p_in_b(st, st->p8, st->max))
	{
		//closest_index(st, n, m);
		on_fait_des_essais(st, st->p8, st->max);
	}
	now_we_sort(st);
}

void	now_we_sort(t_stack *st)
{
	int	i;
	int	lol;

	i = 0;
	while (!is_p_in_a_sorted(st, st->p9, st->max))
	{
		if (st->b[i] >= st->p9 && st->b[i] < st->max)
		{
			lol = find_big(st);
			if (lol < ((st->len - st->index -1) /2))
			{
				while (lol > 0)
				{
					rotate_b(st, 0);
					lol--;
				}
				push_a(st);
			}
			else
			{
				while (lol <= (st->len - st->index -1))
				{
					r_rotate_b(st, 0);
					lol++;
				}
				push_a(st);
			}
		}
		i++;
	}
}

int	find_big(t_stack *st)
{
	int	i;
	int	big;
	int	index;

	i = 0;
	big = INT32_MIN;
	while(st->b[i])
	{
		if (st->b[i] > big)
		{
			index = i;
			big = st->b[i];
		}
		i++;
	}
	return (index);
}

void	algo_v2_0_2(t_stack *st, int n)
{
	int	m;
	if (n == st->min)
		m = st->p1;
	else if (n == st->p2)
		m = st->p3;
	else if (n == st->p4)
		m = st->mid;
	else if (n == st->p6)
		m = st->p7;
	else if (n == st->p8)
		m = st->p9;
	if ((st->b[0] >= st->o[n] && st->b[0] < st->o[m]))
		rotate_b(st, 0);
}
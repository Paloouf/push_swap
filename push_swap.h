/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:18:16 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/18 15:42:47 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*o;
	int	index;
	int	len;
	int	min;
	int	max;
	int	mid;

} t_stack;

void	push_a(t_stack *st);
void	push_b(t_stack *st);
void	swap_a(t_stack *st, int flag);
void	swap_b(t_stack *st, int flag);
void	sswap(t_stack *st);
int	make_stacks(t_stack *st, int argc, char **argv);
int	make_index(t_stack *st);
void	fill_a(t_stack *st, char **argv);
void	fill_a_split(t_stack *st, char **splitted);
void	rotate_b(t_stack *st, int flag);
void	rotate_a(t_stack *st, int flag);
void	ra_rb(t_stack *st);
void	r_rotate_b(t_stack *st, int flag);
void	r_rotate_a(t_stack *st, int flag);
void	r_ra_rb(t_stack *st);
void	refill_a(t_stack *st);
int	is_sorted(t_stack *st);
void	algo_one(t_stack *st);
void	algo_two(t_stack *st);
void	algo_three(t_stack *st);
int	is_b_sorted(t_stack *st);
int	is_a_sorted(t_stack *st);
void	algo_v2(t_stack *st);
void	algo_v2_0_1(t_stack *st);
void	algo_v2_0_2(t_stack *st, float n);
int	is_p_in_b(t_stack *st, float n, float m);
void	best_choice(t_stack *st, int i, float n, float m);
void	closest_index(t_stack *st, float n, float m);
//void	quicksort(t_stack *st, int low, int high);
//int	partition(t_stack *st, int low, int high);


#endif
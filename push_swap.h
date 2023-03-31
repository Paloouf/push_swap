/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:18:16 by ltressen          #+#    #+#             */
/*   Updated: 2023/03/31 10:35:41 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	index;
	int	len;

} t_stack;

void	push_a(t_stack *stacks);
void	push_b(t_stack *stacks);
void	swap_a(t_stack *stacks, int flag);
void	swap_b(t_stack *stacks, int flag);
void	sswap(t_stack *stacks);
int	make_stacks(t_stack *stacks, int argc, char **argv);
void	fill_a(t_stack *stacks, char **argv);
void	fill_a_split(t_stack *stacks, char **splitted);
void	rotate_b(t_stack *stacks, int flag);
void	rotate_a(t_stack *stacks, int flag);
void	ra_rb(t_stack *stacks);
void	r_rotate_b(t_stack *stacks, int flag);
void	r_rotate_a(t_stack *stacks, int flag);
void	r_ra_rb(t_stack *stacks);
int	is_sorted(t_stack *stacks);
void	algo_one(t_stack *stacks);
void	algo_two(t_stack *stacks);
int	is_b_sorted(t_stack *stacks);


#endif
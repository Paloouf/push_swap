/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltressen <ltressen@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:29:52 by ltressen          #+#    #+#             */
/*   Updated: 2023/04/25 14:44:58 by ltressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	st;

	if (argc >= 2)
	{
		if (!make_stacks(&st, argc, argv))
			return (0);
		checker(&st);
		free(st.a);
		free(st.b);
		free(st.o);
	}
	return (0);
}

int	checker(t_stack *st)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!apply_stack_op(st, line))
			return (0);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(st) && st->index == st->len)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}

int	apply_stack_op(t_stack *st, char *line)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		swap_a(st, 1);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		swap_b(st, 1);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		sswap(st, 1);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		push_a(st, 1);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		push_b(st, 1);
	else if (!apply_stack_rot(st, line))
		return (0);
	return (1);
}

int	apply_stack_rot(t_stack *st, char *line)
{
	if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		rotate_a(st, 1);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		rotate_b(st, 1);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		ra_rb(st, 1);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		r_rotate_a(st, 1);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		r_rotate_b(st, 1);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		r_ra_rb(st, 1);
	else
		return (0);
	return (1);
}

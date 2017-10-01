/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:20:00 by tberthie          #+#    #+#             */
/*   Updated: 2017/10/01 17:01:26 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tools.h"

#include <unistd.h>
#include <stdlib.h>

void			operate(char *op, t_stack *a, t_stack *b, int *ops)
{
	if (op[0] == 's' && op[1] != 's')
		swap(op[1] == 'a' ? a : b);
	else if (op[0] == 's' && op[1] == 's')
		double_operator('s', a, b);
	else if (op[0] == 'p')
		op[1] == 'a' ? push(a, b) : push(b, a);
	else if (op[0] == 'r' && op[1] != 'r')
		rotate(op[1] == 'a' ? a : b, 0);
	else if (op[0] == 'r' && op[1] == 'r' && !op[2])
		double_operator('r', a, b);
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r')
		double_operator('R', a, b);
	else
		rotate(op[2] == 'a' ? a : b, 1);
	ft_print(1, "%s\n", op);
	free(op);
	(*ops)++;
}

int				main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		flag;

	if (ac <= 1)
		return (0);
	av += (flag = !ft_strcmp(av[1], "-v"));
	a = (t_stack*)ft_memalloc(sizeof(t_stack));
	b = (t_stack*)ft_memalloc(sizeof(t_stack));
	a->stack = (int*)ft_m(sizeof(int) * (unsigned int)(ac - 1));
	b->stack = (int*)ft_m(sizeof(int) * (unsigned int)(ac - 1));
	while (*++av)
	{
		if (!check_nbr(*av, &a->stack[a->size], a))
		{
			write(2, "\x1b[31mError\n", 11);
			return (0);
		}
		a->size++;
	}
	if (flag)
		display(a, b);
	ft_print(1, "Ops: %d\n", solve(a, b, flag));
	return (0);
}

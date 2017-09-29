/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:20:00 by tberthie          #+#    #+#             */
/*   Updated: 2017/09/29 18:13:23 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tools.h"

#include <unistd.h>

static void		split(t_stack *a, t_stack *b, char flag)
{
	int		rot;

	rot = a->size;
	while (rot > 0 && a->size > 1)
	{
		if (a->stack[0] > a->stack[a->size - 1])
		{
			push(a, b);
			ft_print(1, "pa\n");
			display(a, b);
			rot--;
		}
		else
		{
			ft_print(1, "ra\n");
			rotate(a, 0);
			display(a, b);
		}
		rot--;
	}
	display(a, b);
	rotate(a, 1);
}

static void		merge(t_stack *a, t_stack *b, char flag)
{

}

static void		solve(t_stack *a, t_stack *b, char flag)
{
	if (check(a, b))
		return ;
	if (a->size >= 2 && a->stack[0] > a->stack[1])
	{
		ft_print(1, "sa\n");
		swap(a);
	}
	else if (!b->size)
		split(a, b, flag);
	else
		merge(a, b, flag);
	if (flag)
		display(a, b);
	solve(a, b, flag);
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
	solve(a, b, flag);
	return (0);
}

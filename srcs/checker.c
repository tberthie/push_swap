/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:17:15 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/21 02:13:40 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "tools.h"

#include <unistd.h>
#include <stdlib.h>

static char		check(t_stack *a, t_stack *b)
{
	if (b->size)
		return (0);
	while (a->size-- > 1)
		if (a->stack[a->size] < a->stack[a->size - 1])
			return (0);
	return (1);
}

static char		exec(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "sb"))
		swap(cmd[1] == 'a' ? a : b);
	else if (!ft_strcmp(cmd, "ss"))
		double_operator('s', a, b);
	else if (!ft_strcmp(cmd, "pa") || !ft_strcmp(cmd, "pb"))
		cmd[1] == 'a' ? push(b, a) : push(a, b);
	else if (!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rb"))
		rotate(cmd[1] == 'a' ? a : b, 0);
	else if (!ft_strcmp(cmd, "rr"))
		double_operator('r', a, b);
	else if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb"))
		rotate(cmd[2] == 'a' ? a : b, 1);
	else if (!ft_strcmp(cmd, "rrr"))
		double_operator('R', a, b);
	else
		return (0);
	return (1);
}

static char		input(t_stack *a, t_stack *b, char flag)
{
	char	*cmd;

	while ((cmd = ft_gnl(0)))
	{
		if (!exec(cmd, a, b))
		{
			write(2, "\x1b[31mError\n", 11);
			return (0);
		}
		if (flag)
			display(a, b);
		free(cmd);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	char		flag;

	if (ac <= 1)
		return (0);
	av += (flag = !ft_strcmp(av[1], "-v"));
	a.stack = (int*)ft_m(sizeof(int) * (unsigned int)(ac - 1));
	b.stack = (int*)ft_m(sizeof(int) * (unsigned int)(ac - 1));
	a.size = 0;
	b.size = 0;
	while (*++av)
	{
		if (!check_nbr(*av, &a.stack[a.size], &a))
		{
			write(2, "\x1b[31mError\n", 11);
			return (0);
		}
		a.size++;
	}
	if (flag)
		display(&a, &b);
	if (input(&a, &b, flag))
		ft_putstr(check(&a, &b) ? "\x1b[32mOK\n" : "\x1b[31mKO\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:17:15 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/20 23:56:16 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(cmd, "pa") || !ft_strcmp(cmd, "pb"))
		cmd[1] == 'a' ? push(b, a) : push(a, b);
	else if (!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rb"))
		rotate(cmd[1] == 'a' ? a : b);
	else if (!ft_strcmp(cmd, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb"))
		reverse_rotate(cmd[2] == 'a' ? a : b);
	else if (!ft_strcmp(cmd, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

static char		input(t_stack *a, t_stack *b)
{
	char	*cmd;

	while ((cmd = ft_gnl(0)))
	{
		if (!exec(cmd, a, b))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		free(cmd);
	}
	return (1);
}

static char		getnbr(char *str, int *dst, t_stack *a)
{
	char	*tmp;
	int		i;

	*dst = 0;
	if (!*str)
		return (0);
	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
		*dst += *dst * 9 + str[i++] - '0';
	if (!i || ft_strcmp(str, (tmp = ft_itoa(*dst))))
		return (0);
	free(tmp);
	i = 0;
	while (i < a->size)
		if (a->stack[i++] == *dst)
			return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	if (ac > 1)
	{
		a.stack = (int*)ft_m(sizeof(int) * (unsigned int)(ac - 1));
		b.stack = (int*)ft_m(sizeof(int) * (unsigned int)(ac - 1));
		a.size = 0;
		b.size = 0;
		while (*++av)
		{
			if (!getnbr((*av) + (**av == '-'), &a.stack[a.size], &a))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			a.stack[a.size++] *= **av == '-' ? -1 : 1;
		}
		if (input(&a, &b))
			write(1, check(&a, &b) ? "OK\n" : "KO\n", 3);
	}
	return (0);
}

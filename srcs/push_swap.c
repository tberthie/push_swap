/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:20:00 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/21 02:16:12 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tools.h"

#include <unistd.h>

static void		solve(t_stack *a, t_stack *b, char flag)
{
	//do stuff
	if (flag)
		display(a, b);
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
	solve(&a, &b, flag);
	return (0);
}

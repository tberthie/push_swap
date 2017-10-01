/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:38:40 by tberthie          #+#    #+#             */
/*   Updated: 2017/10/01 17:05:21 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tools.h"

void		solve(t_stack *a, t_stack *b, char flag)
{
	static int	ops = 0;

	if (check(a, b))
	{
		if (flag)
			ft_print(1, "Ops: %d\n", ops);
		return ;
	}

	// algo // operate(ft_strdup("sa"), a, b, &ops);

	if (flag)
		display(a, b);
	solve(a, b, flag);
}

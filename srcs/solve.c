/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:38:40 by tberthie          #+#    #+#             */
/*   Updated: 2017/10/01 17:01:53 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "tools.h"

int			solve(t_stack *a, t_stack *b, char flag)
{
	static int	ops = 0;

	if (check(a, b))
		return (ops);

	// algo // operate(ft_strdup("sa"), a, b, &ops);

	if (flag)
		display(a, b);
	return (solve(a, b, flag));
}

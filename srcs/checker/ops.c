/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:31:30 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/13 12:52:01 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void			swap(int *a, int *b)
{
	int		t;

	t = *a;
	*a = *b;
	*b = t;
}

void			push(t_p *a, t_p *b)
{
	if (b && b->p && *b->p)
	{
		insert(a, *(b->p), a->s++);
		rot(b, 1);
		b->p[--b->s] = 0;
	}
}

void			rot(t_p *a, int t)
{
	int		b;
	int		i;

	if (!a->s)
		return ;
	i = t ? a->s - 1 : 0;
	b = a->p[i];
	if (t)
		while (a->p[i] && a->p[i + 1] && (i += 1))
			a->p[i - 1] = a->p[i];
	else
		while (a->p[i] && a->p[i - 1] && (i -= 1))
			a->p[i + 1] = a->p[i];
	a->p[t ? i - 1 : i + 1] = b;
}

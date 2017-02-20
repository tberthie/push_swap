/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:20:20 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/20 23:08:19 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

void		swap(t_stack *elem)
{
	int		tmp;

	if (elem->size < 2)
		return ;
	tmp = elem->stack[0];
	elem->stack[0] = elem->stack[1];
	elem->stack[1] = tmp;
}

void		push(t_stack *origin, t_stack *dest)
{
	int		i;

	if (!origin->size)
		return ;
	i = 0;
	while (i++ < dest->size)
		dest->stack[i] = dest->stack[i - 1];
	dest->stack[0] = origin->stack[0];
	origin->size--;
	i = 0;
	while (i++ < origin->size)
		origin->stack[i - 1] = origin->stack[i];
}

void		rotate(t_stack *elem)
{

}

void		reverse_rotate(t_stack *elem)
{

}

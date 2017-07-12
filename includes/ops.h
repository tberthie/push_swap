/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:20:48 by tberthie          #+#    #+#             */
/*   Updated: 2017/07/12 16:36:04 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include "libft.h"

typedef	struct	s_stack
{
	int		*stack;
	int		size;

	char	padding[4];
}				t_stack;

void			swap(t_stack *elem);
void			push(t_stack *origin, t_stack *dest);
void			rotate(t_stack *elem, char reverse);
void			double_operator(char op, t_stack *a, t_stack *b);

#endif

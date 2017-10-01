/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:21:19 by tberthie          #+#    #+#             */
/*   Updated: 2017/10/01 17:00:45 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ops.h"

void		operate(char *op, t_stack *a, t_stack *b, int *ops);
int			solve(t_stack *a, t_stack *b, char flag);

#endif

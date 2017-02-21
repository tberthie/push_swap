/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:51:32 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/21 01:15:22 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "ops.h"

void		display(t_stack *a, t_stack *b);
char		check_nbr(char *str, int *dst, t_stack *a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:43:08 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/01 23:07:55 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct		s_p
{
	int		*p;
	int		s;
}					t_p;

void				checker(t_p *a, t_p *b, int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:51:09 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/21 02:08:24 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

#include <stdlib.h>
#include <unistd.h>

static void	get_max(t_stack *a, t_stack *b, int *max)
{
	int			tmp;
	int			i;

	max[0] = 1;
	i = 0;
	while (i < a->size)
		if ((tmp = ft_intlen(a->stack[i++])) > max[0])
			max[0] = tmp;
	max[1] = 1;
	i = 0;
	while (i < b->size)
		if ((tmp = ft_intlen(b->stack[i++])) > max[1])
			max[1] = tmp;
}

static void	fill(int len)
{
	while (len-- > 0)
		write(1, " ", 1);
}

void		display(t_stack *a, t_stack *b)
{
	int			size;
	int			i;
	int			max[2];

	get_max(a, b, max);
	size = a->size > b->size ? a->size : b->size;
	i = 0;
	ft_putstr("\x1b[32mA");
	fill(max[0]);
	ft_putstr("B\x1b[0m\n");
	while (i < size)
	{
		if (a->size > i)
		{
			ft_putnbr(a->stack[i]);
			fill(max[0] - ft_intlen(a->stack[i]) + 1);
		}
		else
			fill(max[0] + 1);
		if (b->size > i)
			ft_putnbr(b->stack[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("\x1b[33m\n");
}

char		check_nbr(char *str, int *dst, t_stack *a)
{
	char	*tmp;
	char	neg;
	int		i;

	*dst = 0;
	neg = *str == '-' ? -1 : 1;
	if (!str[(i = *str == '-')])
		return (0);
	while (str[i] <= '9' && str[i] >= '0')
		*dst += *dst * 9 + str[i++] - '0';
	*dst *= neg;
	if (!i || ft_strcmp(str, (tmp = ft_itoa(*dst))))
		return (0);
	free(tmp);
	i = 0;
	while (i < a->size)
		if (a->stack[i++] == *dst)
			return (0);
	return (1);
}

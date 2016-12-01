/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:11:36 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/01 23:44:47 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

static int		insert(t_p *a, int s, int n)
{
	int		*lp;

	if (!(lp = malloc(sizeof(int) * (n + 1))))
		return (0);
	lp[n] = s;
	while (n--)
	{
		if ((a->p)[n] == s)
			return (0);
		lp[n] = (a->p)[n];
	}
	if (a->p)
		free(a->p);
	a->p = lp;
	return (1);
}

static int		check(char *str, int *n)
{
	int		neg;

	neg = *str == '-' ? -1 : 1;
	str += *str == '-' ? 1 : 0;
	*n = 0;
	while (*str >= '0' && *str <= '9')
		*n += (*n * 9) + *str++ - '0';
	*n *= neg;
	return (*str ? 0 : 1);
}

int				main(int ac, char **av)
{
	t_p		*a;
	t_p		*b;
	int		v[1];
	int		n;

	*v = 0;
	n = 0;
	if (!(a = malloc(sizeof(t_p))) || !(b = malloc(sizeof(t_p))) || (ac == 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	a->p = 0;
	while (*++av)
		if (!check(*av, v) || !insert(a, *v, n++))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	if (n)
		checker(a, b, n);
	return (0);
}

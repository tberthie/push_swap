/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:04:54 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/03 19:00:05 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

static int		*e_insert(char *line, int *i, int n)
{
	int		*ni;
	int		a;

	a = 0;
	if (!(ni = malloc(sizeof(int) * (n + 1))))
		return (0);
	ni[n--] = 0;
	if ((!ft_strcmp(line, "sa") && (a += 1)) || (!ft_strcmp(line, "sb") &&
	(a += 2)) || (!ft_strcmp(line, "ss") && (a += 3)) || (!ft_strcmp(line,
	"pa") && (a += 4)) || (!ft_strcmp(line, "pb") && (a += 5)) ||
	(!ft_strcmp(line, "ra") && (a += 6)) || (!ft_strcmp(line, "rb") &&
	(a += 7)) || (!ft_strcmp(line, "rr") && (a += 8)) || (!ft_strcmp(line,
	"rra") && (a += 9)) || (!ft_strcmp(line, "rrb") && (a += 10)) ||
	(!ft_strcmp(line, "rrr") && (a += 11)))
		ni[n] = a;
	while (n--)
		ni[n] = i[n];
	if (i)
		free(i);
	i = ni;
	return (i);
}

static int		*parse(int *i)
{
	int		n;
	char	*line;
	int		r;

	n = 0;
	while ((r = ft_gnl(0, &line)))
		if (r == -1 || !(!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") ||
		!ft_strcmp(line, "ss") || !ft_strcmp(line, "pa") || !ft_strcmp(line,
		"pb") || !ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") ||
		!ft_strcmp(line, "rr") || !ft_strcmp(line, "rra") || !ft_strcmp(line,
		"rrb") || !ft_strcmp(line, "rrr")) || !(i = e_insert(line, i, ++n)))
			return (0);
	return (i);
}

static void		exec(t_p *a, t_p *b, int i)
{
	if ((i == 3 || i == 1) && a->s > 1)
		swap(&a->p[0], &a->p[1]);
	if ((i == 3 || i == 2) && b->s > 1)
		swap(&b->p[0], &b->p[1]);
	if ((i == 4 && a->s) || (i == 5 && b->s))
		push((i == 4) ? a : b, (i == 4) ? b : a);
	if (i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11)
		rot(i == 6 || i == 9 ? a : b, (i > 8));
	if (i == 8 || i == 11)
		rot(a, (i == 11));
}

void			checker(t_p *a, t_p *b)
{
	int		*i;

	if (!(i = malloc(sizeof(int))) || (*i = 0) ||
	!(i = parse(i)))
		return (ft_putstr_fd("Error\n", 2));
	while (*i)
		exec(a, b, *i++);
	if (b->s)
		return (ft_putstr("KO\n"));
	while (--a->s && *(a->p) && *(a->p + 1))
	{
		ft_printf("{%d}\n", *(a->p));
		if (*(a->p) > *(a->p + 1))
			return (ft_putstr("KO\n"));
		a->p++;
	}
	ft_putstr("OK\n");
}

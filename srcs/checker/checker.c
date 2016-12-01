/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:04:54 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/01 23:44:53 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int				*insert(char *line, int *i, int n)
{
	int		*ni;
	int		a;

	a = 0;
	if (!(ni = malloc(sizeof(int) * (n + 1))))
		return (0);
	ni[n--] = 0;
	if ((!ft_strcmp(line, "sa") && (a = 1)) || (!ft_strcmp(line, "sb") &&
	(a = 2)) || (!ft_strcmp(line, "ss") && (a = 3)) || (!ft_strcmp(line,
	"pa") && (a = 4)) || (!ft_strcmp(line, "pb") && (a = 5)) ||
	(!ft_strcmp(line, "ra") && (a = 6)) || (!ft_strcmp(line, "rb") &&
	(a = 7)) || (!ft_strcmp(line, "rr") && (a = 8)) || (!ft_strcmp(line,
	"rra") && (a = 9)) || (!ft_strcmp(line, "rrb") && (a = 10)) ||
	(!ft_strcmp(line, "rrr") && (a = 11)))
		ni[n] = a;
	while (n--)
		ni[n] = i[n];
	if (i)
		free(i);
	i = ni;
	return (i);
}

int				*parse(int *i)
{
	int		n;
	char	*line;
	int		r;

	n = 0;
	while ((r = get_next_line(0, &line)))
		if (r == -1 || !(!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") ||
		!ft_strcmp(line, "ss") || !ft_strcmp(line, "pa") || !ft_strcmp(line,
		"pb") || !ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") ||
		!ft_strcmp(line, "rr") || !ft_strcmp(line, "rra") || !ft_strcmp(line,
		"rrb") || !ft_strcmp(line, "rrr")) || !(i = insert(line, i, ++n)))
			return (0);
	return (i);
}

void			checker(t_p *a, t_p *b, int n)
{
	int		*i;

	i = 0;
	if (!(i = parse(i)))
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	while (*i)
		ft_printf("{%d}", *i++);
}

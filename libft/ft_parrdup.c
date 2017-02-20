/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:48:56 by tberthie          #+#    #+#             */
/*   Updated: 2017/02/20 19:48:58 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_internal.h"

void	**ft_parrdup(void **array)
{
	void	**n_arr;

	n_arr = ft_parrnew();
	while (*array)
		ft_parrpush(&n_arr, *array++);
	return (n_arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:36:37 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/31 16:17:52 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_bool	ft_malloc(void *target, int size)
{
	void		**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == 0)
		return (0);
	return (1);
}

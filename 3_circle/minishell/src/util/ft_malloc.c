/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:34:59 by hopark            #+#    #+#             */
/*   Updated: 2021/05/18 15:35:00 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_bool	ft_malloc(void *target, int size)
{
	void	**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == NULLPTR)
		return (FALSE);
	return (SUCCESS);
}

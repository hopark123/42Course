/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:47:42 by hopark            #+#    #+#             */
/*   Updated: 2021/05/06 15:53:32 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_bool	ft_malloc(void *target, size_t size)
{
	void	**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == NULLPTR)
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:22:11 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 18:27:06 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc_c(int count, int size, char c)
{
	void	*result;

	if (!(result = malloc(size * count)))
		return (0);
	if (result == 0)
		return (0);
	ft_bzero_c(result, size * count, c);
	return (result);
}

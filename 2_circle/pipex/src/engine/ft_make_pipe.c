/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:20:31 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/13 18:40:42 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	*ft_free_pip(int **pip, int index)
{
	int		i;

	i = 0;
	if (index < 0)
		index = 0;
	while (i < index)
	{
		ft_free(pip[i]);
		i++;
	}
	ft_free(pip);
	return (0);
}

int	**ft_make_pipe(int cnt)
{
	int		**pip;
	int		i;
	int		temp;

	i = 0;
	if (!ft_malloc(&pip, sizeof(int *) * cnt))
		return (ERROR);
	while (i < cnt)
	{
		if (!ft_malloc(&pip[i], sizeof(int) * 2))
			return (ft_free_pip(pip, i - 1));
		if (pipe(pip[i]) == -1)
			return (ft_free_pip(pip, i));
		i++;
	}
	return (pip);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_user.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:02:32 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/13 19:50:47 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*ft_find_user(char **envp)
{
	int		i;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("HOME", envp[i], 4))
		{
			temp = ft_strndup(envp[i] + 5, ft_strlen(envp[i] + 5));
			return (temp);
		}
		i++;
	}
	return (0);
}
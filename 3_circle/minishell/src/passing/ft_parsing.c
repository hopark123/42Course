/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:26 by hopark            #+#    #+#             */
/*   Updated: 2021/06/18 16:23:35 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_parsing(t_built *built, t_list *env_list)
{
	int		res;

	if (!built || !built->command)
		return (0);

	if (ft_strncmp(built->command->str, "echo", 4))
		res = ft_echo(built);
	else if (ft_strncmp(built->command->str, "cd", 2))
		res = ft_cd(built, env_list);
	else if (ft_strncmp(built->command->str, "pwd", 3))
		res = ft_pwd(built);
	else if (ft_strncmp(built->command->str, "export", 6))
		res = ft_export(built, env_list);
	else if (ft_strncmp(built->command->str, "unset", 5))
		res = ft_unset(built, env_list);
	else if (ft_strncmp(built->command->str, "env", 3))
		res = ft_env(built, env_list);
	// else if (ft_strncmp(built->command->str, "exit", 4))
		// res = ft_exit();
	else if (ft_strchr("><|;", built->command->str))
		res = ft_parsing2(built, env_list);
	else
		return (0);
	return (res);
}

int	ft_parsing2(t_built *built, t_list *env_list)
{
	if (ft_strncmp(built->command->str, ">>", 2))
		ft_redirect1(built);
	else if (ft_strncmp(built->command->str, ">", 1))
		ft_redirect1(built);
	else if (ft_strncmp(built->command->str, "<<", 2))
		ft_redirect1(built);
	else if (ft_strncmp(built->command->str, "<", 1))
		ft_redirect1(built);
}

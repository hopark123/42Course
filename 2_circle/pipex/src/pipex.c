/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:14:09 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/14 19:23:19 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	ft_init_pipex(t_pipex *pipex, int argc, char **argv, char**envp)
{
	int		i;
	t_list	*temp;

	i = 2;
	pipex->envp = envp;
	pipex->home = ft_find_user(envp);
	pipex->cmd = 0;
	if (ft_strncmp(argv[1], "here_doc", 8))
	{
		ft_heredoc(pipex, argc, argv);
		i++;
	}
	else
		ft_redirect(pipex, argc, argv);
	while (i < argc - 1)
	{
		temp = ft_listnew(argv[i]);
		ft_listadd_tail(&(pipex->cmd), &temp);
		i++;
	}
}

static void	ft_end_pipex(t_pipex *pipex)
{
	ft_listclear(&(pipex->cmd));
	ft_free(pipex->home);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		return (ERROR);
	ft_init_pipex(&pipex, argc, argv, envp);
	ft_run_pipex(&pipex);
	ft_end_pipex(&pipex);
	return (0);
}

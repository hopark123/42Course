/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:14:09 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/13 19:40:37 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static char	*judge_execfile(char *str)
{
	char		*command;

	if (!str)
		return (0);
	command = ft_strndup(str, ft_strlen(str));
	if (!command)
		write(2, "fail\n", 2);
	if (access(command, X_OK) == -1)
	{
		write(2, "fail\n", 2);
	}
	else
		return (command);
	ft_free(command);
	return (0);
}

static char	*judge_command(char *str)
{
	char		*bin;
	char		*ubin;

	if (!str)
		return (0);
	bin = ft_strjoin("/bin/", str);
	ubin = ft_strjoin("/usr/bin/", str);
	if (!bin || !ubin)
		return (ERROR);
	if (access(bin, X_OK) == -1)
	{
		ft_free(bin);
		if (access(ubin, X_OK) == -1)
		{
			ft_free(ubin);
			return (ERROR);
		}
		return (ubin);
	}
	ft_free(ubin);
	return (bin);
}

static char	**change_content(char **str, char *home)
{
	char	*tmp;
	char	*join;
	int		i;

	i = 0;
	join = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i][0] == '~')
		{
			tmp = ft_strjoin(home, &str[i][1]);
			free(str[i]);
			str[i] = tmp;
		}
		i++;
	}
	tmp = str[0];
	if (ft_strchr(tmp, '/'))
		str[0] = judge_execfile(tmp);
	else
		str[0] = judge_command(tmp);
	free(tmp);
	return (str);
}

int	ft_execve(t_pipex *pipex, int index)
{
	int		pid;
	char	**argv;
	t_list	*temp;

	pid = fork();
	temp = ft_list_next(pipex->cmd, index);
	argv = ft_split(temp->str, ' ');
	argv = change_content(argv, pipex->home);
	if (pid < 0)
		return (ERROR);
	else if (pid == 0)
	{
		dup2(pipex->fd[index][0], STDIN_FILENO);
		test_str("execve", argv[0]);
		if (execve(argv[0], argv, pipex->envp) < 0)
			return (ERROR);
	}
	else
	{
		dup2(pipex->fd[index][1], STDOUT_FILENO);
	}
	return (0);
}

int	ft_run_pipex(t_pipex *pipex)
{
	t_list	*t_cmd;
	int		i;

	t_cmd = pipex->cmd;
	i = 0;
	while (t_cmd)
	{
		ft_execve(pipex, i);
		t_cmd = t_cmd->next;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_list	*temp;
	t_pipex	pipex;

	if (argc < 5)
		return (ERROR);
	pipex.envp = envp;
	if (ft_strncmp(argv[1], "here_doc", 8))
	{
		ft_init_heredoc(argc, argv);
		pipex.fd = ft_make_pipe(argc - 4);
		i = 3;
	}
	else
	{
		ft_init_pipe(argc, argv);
		pipex.fd = ft_make_pipe(argc - 3);
		i = 2;
	}
	while (i < argc - 1)
	{
		temp = ft_listnew(argv[i]);
		ft_listadd_tail(&(pipex.cmd), &temp);
		i++;
	}
	pipex.home = ft_find_user(envp);
	ft_run_pipex(&pipex);
	return (0);
}

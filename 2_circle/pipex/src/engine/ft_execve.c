/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:49:58 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/14 20:04:28 by hjpark           ###   ########.fr       */
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

static void	ft_parents(t_pipex *pipex, int *t_pip, int pid)
{
	int		status;

	status = 0;
	waitpid(pid, &status, WUNTRACED);
	while (!WIFEXITED(status) && !WIFSIGNALED(status))
		waitpid(pid, &status, WUNTRACED);
	ft_close(pipex->pip[0]);
	ft_close(t_pip[1]);
	pipex->pip[0] = t_pip[0];
}

int	ft_execve(t_pipex *pipex, int *t_pip, int index)
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
		dup2(pipex->pip[0], STDIN_FILENO);
		ft_close(pipex->pip[0]);
		dup2(t_pip[1], STDOUT_FILENO);
		ft_close(t_pip[1]);
		if (execve(argv[0], argv, pipex->envp) < 0)
			return (ERROR);
	}
	else
		ft_parents(pipex, t_pip, pid);
	ft_free2(argv);
	return (0);
}

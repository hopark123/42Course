/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:52:14 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/14 20:12:53 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	ft_outfile(t_pipex *pipex)
{
	int		read_size;
	char	*line;

	read_size = 1;
	while (read_size > 0)
	{
		read_size = get_next_line(pipex->pip[0], &line);
		if (read_size <= 0)
			break ;
		ft_putstr_fd(line, pipex->out, 0);
		ft_putstr_fd("\n", pipex->out, 0);
		ft_free(line);
	}
	if (read_size == 0)
		ft_free(line);
	ft_close(pipex->pip[0]);
	ft_close(pipex->out);
}

int	ft_run_pipex(t_pipex *pipex)
{
	t_list	*t_cmd;
	int		pip_in[2];
	int		i;

	t_cmd = pipex->cmd;
	i = 0;
	while (t_cmd)
	{
		pipe(pip_in);
		ft_execve(pipex, pip_in, i);
		t_cmd = t_cmd->next;
		i++;
	}
	ft_outfile(pipex);
	return (0);
}

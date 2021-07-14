/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:52:14 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/14 19:07:02 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_run_pipex(t_pipex *pipex)
{
	t_list	*t_cmd;
	int		i;
	int		pip_in[2];
	char	*line;

	t_cmd = pipex->cmd;
	i = 0;
	while (t_cmd)
	{
		pipe(pip_in);
		ft_execve(pipex, pip_in, i);
		t_cmd = t_cmd->next;
		i++;
	}
	while (get_next_line(pipex->pip[0], &line) > 0)
	{
		ft_putstr_fd(line, pipex->out, 0);
		ft_putstr_fd("\n", pipex->out, 0);
		ft_free(line);
	}
	ft_close(pipex->pip[0]);
	ft_close(pipex->out);
	return (0);
}

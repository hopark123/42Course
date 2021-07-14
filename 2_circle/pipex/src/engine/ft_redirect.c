/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:19:03 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/14 18:54:04 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_redirect(t_pipex *pipex, int argc, char**argv)
{
	int		temp;

	temp = open(argv[1], O_RDONLY, S_IRWXU);
	dup2(temp, STDIN_FILENO);
	ft_close(temp);
	pipex->out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
}

void	ft_heredoc(t_pipex *pipex, int argc, char**argv)
{
	char	*line;

	pipe(pipex->pip);
	while (get_next_line(STDIN_FILENO, &line) >= 0)
	{
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])))
		{
			ft_free(line);
			ft_close(pipex->pip[1]);
			break ;
		}
		ft_putstr_fd(line, pipex->pip[1], 0);
		ft_putstr_fd("\n", pipex->pip[1], 0);
		ft_free(line);
	}
	pipex->out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
}

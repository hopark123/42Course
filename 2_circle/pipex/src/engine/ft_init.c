/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:19:03 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/13 19:34:52 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_init_pipe(int argc, char**argv)
{
	int		temp;

	temp = open(argv[1], O_RDONLY, S_IRWXU);
	dup2(temp, STDIN_FILENO);
	ft_close(temp);
	temp = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	dup2(temp, STDOUT_FILENO);
	ft_close(temp);
}

void	ft_init_heredoc(int argc, char**argv)
{
	int		temp;
	/// to do heredoc
	temp = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	dup2(temp, STDOUT_FILENO);
	ft_close(temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:52:21 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 20:13:29 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	ft_exit(t_inf *inf, char *msg, int fd)
{
	if (inf->a_h)
		ft_listclear(&inf->a_h);
	if (inf->b_h)
		ft_listclear(&inf->b_h);
	ft_putstr_fd(msg, fd, 0);
	ft_free(inf);
	exit(0);
}

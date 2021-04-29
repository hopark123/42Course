/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:44 by hopark            #+#    #+#             */
/*   Updated: 2020/12/17 16:40:16 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int n2;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = (unsigned int)n * (-1);
	}
	else
		n2 = (unsigned int)n;
	if (n2 >= 10)
		ft_putnbr_fd((int)(n2 / 10), fd);
	ft_putchar_fd((int)(n2 % 10 + '0'), fd);
}
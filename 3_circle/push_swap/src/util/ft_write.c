/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:25:44 by hopark            #+#    #+#             */
/*   Updated: 2021/05/11 16:18:25 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putchar_fd(char c, int fd, char *color)
{
	write(1, color, 6);
	write(fd, &c, 1);
	write(1, "\x1b[0m", 5);
}

void	ft_putstr_fd(char *s, int fd, char *color)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (i < ft_strlen(s))
	{
		ft_putchar_fd(s[i], fd, color);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd, char *color)
{
	unsigned int	n2;

	if (n < 0)
	{
		ft_putchar_fd('-', fd, color);
		n2 = (unsigned int)n * (-1);
	}
	else
		n2 = (unsigned int)n;
	if (n2 >= 10)
		ft_putnbr_fd((int)(n2 / 10), fd, color);
	ft_putchar_fd((int)(n2 % 10 + '0'), fd, color);
}

void	ft_putnbr_fd2(int n, int fd, char *color)
{
	int		n2;

	n2 = n;
	while (n2--)
		ft_putchar_fd('x', fd, color);
}

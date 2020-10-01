/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:04:40 by hopark            #+#    #+#             */
/*   Updated: 2020/10/01 17:09:47 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int n2;

	if (n == 0 || fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = (unsigned int)n * (-1)	;
	}
	if (n2 >= 10)
		ft_putnbr_fd((int)(n2 / 10), fd);
	ft_putnbr_fd((int)(n2 % 10 + '0'), fd);
}

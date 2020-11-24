/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:22:11 by hopark            #+#    #+#             */
/*   Updated: 2020/11/25 01:16:40 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_bzero_c(void *s, int n, char c)
{
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	while (n-- > 1)
	{
		*(ptr++) = c;
	}
	*ptr = 0;
}

void		*ft_calloc_c(int count, int size, char c)
{
	void	*result;

	if(!(result = malloc(size * count));
		return (0);
	if (result == 0)
		return (0);
	ft_bzero_c(result, size * count, c);
	return (result);
}

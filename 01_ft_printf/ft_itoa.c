/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:30:41 by hopark            #+#    #+#             */
/*   Updated: 2020/11/24 22:37:01 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_int_len(int n)
{
	int		len;
	long long	n2;

	len = 0;
	n2 = (long long)n;
	if (n2 < 0)
	{
		len++;
		n2 *= -1;
	}
	while (n2 >= 10)
	{
		len++;
		n2 /= 10;
	}
	return (++len);
}

char			*ft_itoa(int n)
{
	int		len;
	int		i;
	long long	n2;
	char		*result;

	len = ft_int_len(n);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	i = 0;
	n2 = n < 0 ? (long long)n * -1 : (long long)n;
	while (i < len)
	{
		result[len - i - 1] = n2 % 10 + '0';
		n2 /= 10;
		i++;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:26:44 by hopark            #+#    #+#             */
/*   Updated: 2020/07/23 18:49:35 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcpy(char *s1, char *s2)
{
	int index;

	index = 0;
	while (s2[index])
	{
		s1[index] = s2[index];
		index++;
	}
	return(s1);
}

#include <stdio.h>

int main(void)
{
	char str1[] = "Flavio";
	char str2[] = "Gaucho";

	printf("%s\n", str1);
	ft_strcpy(str1, str2);
	printf("%s\n", str1);
	return (0);
}

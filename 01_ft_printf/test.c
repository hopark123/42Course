/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:49:02 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 04:00:28 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main()
{
	// -------int------
	char *format = "@%5.d@\n";
	// long long c = -9223372036854775808;
	long long c = LLONG_MIN;
	printf("AAAA : %lld\n", LLONG_MIN);
	printf("ft\n");
	ft_printf(format,c);
	printf("\n");
	printf("pf\n");
	printf(format,c);

	// -------char------
	// char *format = "@%+0.0c@\n";
	// char c = 'a';
	// printf("ft\n");
	// ft_printf(format,c);
	// printf("\n");
	// printf("pf\n");
	// printf(format,c);

	// // -------string------
	// char *format = "*%.12s*\n";
	// char *c = 0;
	// printf("ft\n");
	// ft_printf(format,c);
	// printf("\n");
	// printf("pf\n");
	// printf(format,c);

}



	// char *format = "@%5.d@\n";
	// long long c = -9223372036854775808;
	// long long c = LLONG_MIN;
	// printf("AAAA : %lld\n", LLONG_MIN);
	// printf("ft\n");
	// ft_printf(format,c);
	// printf("\n");
	// printf("pf\n");
	// printf(format,c);

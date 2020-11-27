/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:49:02 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 19:48:48 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main()
{
	// -------int------
	// char *format = "@%5x@\n";
	// long long c = 245;x
	// long long c = -9223372036854775808;
	// long long c = LLONG_MIN;
	// printf("AAAA : %lld\n", LLONG_MIN);
	// printf("ft : %d\n" , ft_printf(format,c));
	// printf("\n");
	// printf("pf : %d\n",	printf(format,c));

	// -------char------
	// char *format = "@%+0.0c@\n";
	// char c = 'a';
	// printf("ft\n");
	// ft_printf(format,c);
	// printf("\n");
	// printf("pf\n");
	// printf(format,c);

	// // -------string------
	char *format = "hello, %s.\n";
	char *c = "gavin";
	printf("pf\n");
	printf(format,c);
	printf("ft\n");
	ft_printf(format,c);
	printf("\n");



	// -------point------
	// char *format = "hello, %s.";
	// char *c = "gavin";
	// // long long c = -9223372036854775808;
	// // long long c = LLONG_MIN;
	// // printf("AAAA : %lld\n", LLONG_MIN);
	// printf("ft : %d\n" , ft_printf(format,c));
	// printf("\n");
	// printf("pf : %d\n",	printf(format, c));






	// char *format = "@%.lld@\n";
	// long long c = -9223372036854775808;
	// // long long c = LLONG_MIN;
	// printf("AAAA : %lld\n", LLONG_MIN);
	// printf("ft\n");
	// ft_printf(format,c);
	// printf("\n");
	// printf("pf\n");
	// printf(format,c);
}

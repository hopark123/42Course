/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:49:02 by hopark            #+#    #+#             */
/*   Updated: 2020/11/29 05:11:12 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
int main()
{

// "%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d" // 1st '*' = -4, 2nd '*' = 0
// < 8, -12, 123456789, , -12345678, 97, -2147483648, 2147483647 --- Return : 60
// ---
// > 8, -12, 123456789, , -12345678, 97, -2147483648, 2147483647 --- Return : 59
	// -------int------%
	char *format ="#%-.0d#";
	char c = 0;
	// long long c = -9223372036854775808;
	// long long c = LLONG_MIN;
	printf("ft : %d\n" , ft_printf(format, c));
	printf("\n");
	printf("pf : %d\n",	printf(format, c));

	// -------char------
	// char *format = "@%+0.0c@\n";
	// char c = 'a';
	// a = 0;
	// *a = 0;
	// printf("this %s is empty\n", c);
	// printf("this %s is empty\n", "");

	// printf("%s",c);

	// ft_printf(format,c);
	// printf("\n");
	// printf("pf\n");
	// printf(format,c);

	// // -------string------
	// char *format = "@%-5c@";
	// char *c = 0;
	// printf("pf\n");
	// printf(format, c);
	// printf("\n");
	// printf("ft\n");
	// ft_printf(format, c);
	// printf("\n");



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

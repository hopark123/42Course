/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:49:02 by hopark            #+#    #+#             */
/*   Updated: 2020/12/11 17:22:22 by hopark           ###   ########.fr       */
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
	int c = 42;

	char *format ="%-2c";
	// ft_printf(format,c);
	ft_printf("\nft : %d\n" , ft_printf(format,c));
	printf("\npf : %d\n",	printf(format,c));
	// char *format2 ="#%.x#";
	// ft_printf("ft : %x\n" , ft_printf(format2,c));
	// printf("pf : %x\n",	printf(format2,c));
	// char *format3 ="#%#-4.d#";
	// ft_printf("ft : %x\n" , ft_printf(format3,c));
	// printf("pf : %x\n",	printf(format3,c));
	// char *format4 ="#%04x#";
	// ft_printf("ft : %x\n" , ft_printf(format4,c));
	// printf("pf : %x\n",	printf(format4,c));
	// char *format5 ="#%-4.x#";
	// ft_printf("ft : %x\n" , ft_printf(format5,0,c));
	// printf("pf : %x\n",	printf(format5,0,c));
	// char *format6 ="#%#-4.*x#";
	// ft_printf("ft : %x\n" , ft_printf(format6,-4,c));
	// printf("pf : %x\n",	printf(format6,-4,c));
	// char *format7 ="#%#04x#";
	// ft_printf("ft : %x\n" , ft_printf(format7,c));
	// printf("pf : %x\n",	printf(format7,c));
	// char *format8 ="#%#-4.*x#";
	// ft_printf("ft : %x\n" , ft_printf(format8,-1,c));
	// printf("pf : %x\n",	printf(format8,-1,c));
	// char *format10 ="#%#04x#";
	// ft_printf("ft : %x\n" , ft_printf(format10,c));
	// printf("pf : %x\n",	printf(format10,c));
	// char *format9 ="#%#-4.*x#";
	// ft_printf("ft : %x\n" , ft_printf(format9,1,c));
	// printf("pf : %x\n",	printf(format9,1,c));
	// char *format11 ="#%#0*.x#";
	// ft_printf("ft : %x\n" , ft_printf(format11,4,c));
	// printf("pf : %x\n",	printf(format11,4,c));
	// char *format12 ="#%#0*.*x#";
	// ft_printf("ft : %x\n" , ft_printf(format12,6,-3,c));
	// printf("pf : %x\n",	printf(format12,6,-1,c));
	// char *format13 ="#%#04.3x#";
	// ft_printf("ft : %x\n" , ft_printf(format13,1,c));
	// printf("pf : %x\n",	printf(format13,1,c));
	// char *format14 ="#%#04x#";
	// ft_printf("ft : %x\n" , ft_printf(format14,1,c));
	// printf("pf : %x\n",	printf(format14,1,c));
	// char *format15 ="#%#03x#";
	// ft_printf("ft : %x\n" , ft_printf(format15,1,c));
	// printf("pf : %x\n",	printf(format15,1,c));
	// 	char *format16 ="#%#0.*x#";
	// ft_printf("ft : %x\n" , ft_printf(format16,2,c));
	// printf("pf : %x\n",	printf(format1,2,c));
// //1

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

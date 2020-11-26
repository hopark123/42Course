/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:51:17 by hopark            #+#    #+#             */
/*   Updated: 2020/11/27 03:00:48 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "ft_printf_type.h"
# include "ft_printf_parse.h"
# include <stdio.h>


void				ft_make_content(t_infor *infor, va_list ap);
void				ft_print_char(t_infor *infor, va_list ap);
void				ft_printf_char(t_infor *infor, va_list ap, char c);
void				ft_print_int(t_infor *infor, va_list ap);
void				ft_printf_int(t_infor *infor, va_list ap, char c);
long long			ft_int_size(t_infor *infor, va_list ap);
void				ft_int_nz_wl(t_infor *infor, long long number, char c);
void				ft_int_nz_wr(t_infor *infor, long long number, char c);
void				ft_int_nz_nsign(t_infor *infor, long long number, char c);
void				ft_int_nz_sign(t_infor *infor, long long number, char c);
void				ft_print_uint(t_infor *infor, va_list ap);
void				ft_printf_uint(t_infor *infor, va_list ap, char c);
unsigned long long	ft_uint_size(t_infor *infor, va_list ap);
void				ft_uint_nz_wl(t_infor *infor, unsigned long long number, char c);
void				ft_uint_nz_wr(t_infor *infor, unsigned long long number, char c);
void				ft_uint_nz_nsign(t_infor *infor, unsigned long long number, char c);
void				ft_uint_nz_sign(t_infor *infor, unsigned long long number, char c);
void				ft_print_string(t_infor *infor, va_list ap);
void				ft_printf_string(t_infor *infor, va_list ap, char c);
char				*ft_put_null(char *temp);



#endif

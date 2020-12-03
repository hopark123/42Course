/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:51:17 by hopark            #+#    #+#             */
/*   Updated: 2020/12/03 20:51:48 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "ft_printf_type.h"
# include "ft_printf_parse.h"

char				*ft_hexa_itoa(t_infor *infor, char *base,\
						unsigned long long num, int i);
int					ft_hexa_len(char *base, unsigned long long num);
void				ft_make_content(t_infor *infor, va_list ap);
void				ft_print_char(t_infor *infor, va_list ap);
void				ft_printf_char(t_infor *infor);
void				ft_char_z(t_infor *infor);
void				ft_char_null(t_infor *infor);
void				ft_print_hexa(t_infor *infor, va_list ap);
unsigned long long	ft_hexa_size(t_infor *infor, va_list ap);
void				ft_hexa_null(t_infor *infor);
void				ft_printf_hexa(t_infor *infor);
void				ft_hexa_z(t_infor *infor);
void				ft_hexa_hz(t_infor *infor);
void				ft_hexa_hl(t_infor *infor);
void				ft_hexa_hr(t_infor *infor);
void				ft_hexa_nhl(t_infor *infor);
void				ft_hexa_nhr(t_infor *infor);
void				ft_print_int(t_infor *infor, va_list ap);
void				ft_printf_int(t_infor *infor);
long long			ft_int_size(t_infor *infor, va_list ap);
void				ft_int_null(t_infor *infor);
void				ft_int_z_w(t_infor *infor);
void				ft_int_z(t_infor *infor);
void				ft_int_nz_wl(t_infor *infor);
void				ft_int_nz_wr(t_infor *infor);
void				ft_int_nz_nsign(t_infor *infor);
void				ft_int_nz_sign(t_infor *infor);
void				ft_print_uint(t_infor *infor, va_list ap);
unsigned long long	ft_uint_size(t_infor *infor, va_list ap);
void				ft_print_string(t_infor *infor, va_list ap);
void				ft_printf_string(t_infor *infor, va_list ap, char c);
char				*ft_put_null(char *temp);



#endif

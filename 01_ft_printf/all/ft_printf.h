/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:51:17 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 19:31:00 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "ft_printf_type.h"
# include "ft_printf_parse.h"

void		ft_make_content(t_infor *infor, va_list ap);
void		ft_printchar(t_infor *infor, va_list ap);
void		ft_printchar2(t_infor *infor, va_list ap, char c);
void		ft_printint(t_infor *infor, va_list ap);
void		ft_printint2(t_infor *infor, va_list ap, char c);
void		ft_int_nz_wl(t_infor *infor, int number, char c);
void		ft_int_nz_wr(t_infor *infor, int number, char c);
void		ft_int_nz_nsign(t_infor *infor, int number, char c);
void		ft_int_nz_sign(t_infor *infor, int number, char c);
void		ft_printstring(t_infor *infor, va_list ap);
void		ft_printstring2(t_infor *infor, va_list ap, char c);
int			ft_printf(const char *format, ...);
int			ft_print(char **format, va_list ap);

#endif

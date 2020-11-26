/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:39:22 by hopark            #+#    #+#             */
/*   Updated: 2020/11/26 19:32:22 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSE_H
# define FT_PRINTF_PARSE_H

# include "libft.h"
# include "ft_printf_type.h"
# include <stdlib.h>

void		ft_check_flag(char **format, t_infor *infor);
void		ft_check_precision(char **format, t_infor *infor, va_list ap);
void		ft_check_width(char **format, t_infor *infor, va_list ap);
void		ft_init_flag(t_flag *flag);
t_infor		*ft_init_infor(t_infor *infor);
int			ft_parsing(char **format, va_list ap, t_infor *infor);

#endif

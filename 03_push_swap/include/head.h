/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:06:13 by hopark            #+#    #+#             */
/*   Updated: 2021/04/29 16:01:27 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define ERROR					0
# define SUCESS					1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX	10240
# endif

typedef struct	s_list
{
	int				num;
	int				chunk;
	struct s_list	*prev;
	struct s_list	*next;

}				t_list;

typedef struct	s_inf
{
	struct s_list	*a_h;
	struct s_list	*a_t;
	struct s_list	*b_h;
	struct s_list	*b_t;
}				t_inf;


/////////////////////////////////////








///////////////////////////////////

void			ft_action(t_inf *inf, char *com);
int				ft_swap_tool(t_list **type);
int				ft_push_tool(t_list **dest, t_list **src);
int				ft_rotate_tool(t_inf *inf, char *com);
int				ft_revrotate_tool(t_inf *inf, char *com);
int				ft_htsetting(t_inf *inf);

void			ft_make_list(int ac, char **av, t_inf *inf);

void			ft_three_a(t_inf *inf);
void			ft_three_b(t_inf *inf);
void			ft_two_a(t_inf *inf);
void			ft_two_b(t_inf *inf);


int				ft_is_ascending(t_list *list);
int				ft_is_descending(t_list *list);
int				ft_chunk_is_descending(t_list *list);

///////////////////////////////////ft_list
t_list			*ft_n_next(t_list *list, int n);
t_list			*ft_listnew(int num);
void			ft_listadd_front(t_list **list, t_list **new);
void			ft_listadd_back(t_list **list, t_list **new);
void			ft_listdelone(t_list **list);
void			ft_listexcpet(t_list **list);
void			ft_listclear(t_list **list);

int				ft_atoi(const char *nptr);
void			ft_free(void *memory);
void			ft_free2(char **s, int i);
int				ft_max(int n, ...);
int				ft_min(int n, ...);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);

int				ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strndup(const char *s, size_t len);
char			*ft_strchr(const char *s, char c);
int				get_next_line(int fd, char **line);

///////////////////////////
int				ft_sort_a(t_inf *inf, int chunk);
int				ft_sort_b(t_inf *inf, int chunk);
int				ft_show(t_inf *inf, char *com);

#endif
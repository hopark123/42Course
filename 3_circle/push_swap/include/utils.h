/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:59:39 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 16:01:21 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "type.h"

static int	ft_isspace(char c);
int			ft_isdigit(int c);
int			ft_sign(int sign);
int			ft_is_num(const char *nptr);
int			ft_atoi(const char *nptr);
void		ft_bubblesort(int arr[], int size);
void		ft_free(void *memory);
void		ft_free2(char **s, int i);
t_list		*ft_listnew(int num);
void		ft_listadd_front(t_list **list, t_list **new);
void		ft_listadd_back(t_list **list, t_list **new);
void		ft_listdelone(t_list **list);
void		ft_listclear(t_list **list);
t_list		*ft_n_next_list(t_list *list, int n);
void		ft_listexcpet(t_list **list);
t_bool		ft_malloc(void *target, size_t size);
int			ft_max(int n, ...);
int			ft_min(int n, ...);
int			ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strndup(const char *s, size_t len);
char		*ft_strchr(const char *s, char c);
void		*ft_memset(void *s, int c, int n);
int			ft_numlen(int num);
static int	ft_count(char const *s, char c);
static int	ft_wordlen(char const *s, char c);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putchar_fd(char c, int fd, char *color);
void		ft_putnbr_fd(int n, int fd, char *color);
void		ft_putnbr_fd2(int n, int fd, char *color);
static int	storejoin(char **store, char *buf, ssize_t readsize);
static int	make_line(char **store, char **line);
int			get_next_line(int fd, char **line);

#endif
#ifndef UTIL_H
# define UTIL_H

int			ft_close(int fd);
void		test_str(char *type, char *str);
void		test_str2(char *type, char **str);
void		test_int(char *type, int num);
void		test_list(char *type, t_list *list);
void		test_spot(char	*str);
void		ft_free(void *memory);
void		ft_free2(char **s);
t_list		*ft_listnew(char *str);
void		ft_listadd_tail(t_list **list, t_list **new);
void		ft_listdelone(t_list **list);
void		ft_listclear(t_list **list);
void		ft_listclear(t_list **list);
t_list		*ft_list_next(t_list *list, int n);
t_bool		ft_malloc(void *target, int size);
char		**ft_split(char const *s, char c);
int			ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, int n);
char		*ft_strndup(const char *s, int len);
void		*ft_memcpy(void *dst, const void *src, int n);
char		*ft_strchr(const char *s, char c);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_putchar_fd(char c, int fd, char *color);
int			ft_putstr_fd(char *s, int fd, char *color);
int			ft_putnbr_fd(int n, int fd, char *color);
int			get_next_line(int fd, char **line);

#endif
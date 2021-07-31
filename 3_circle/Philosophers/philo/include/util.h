#ifndef UTIL_H
# define UTIL_H

typedef int			t_bool;
# define SUCCESS	1
# define ERROR		0
# define INT_MAX	2147483647
long	ft_atoi(const char *nptr);
void	ft_free(void *memory);
long	ft_get_time(void);
t_bool	ft_malloc(void *target, int size);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strndup(const char *s, int len);
void	*ft_memcpy(void *dst, const void *src, int n);

void	ft_usleep(long time);

#endif
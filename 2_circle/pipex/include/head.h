#ifndef HEAD_H
# define HEAD_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define SUCCESS	1
# define FAIL		-1
# define ERROR		0
# define NULLPTR	0

/////////////////////////////////type

typedef struct	s_list
{
	char			*str;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct	s_pipex
{
	int				**fd;
	char			**envp;
	char			*home;
	struct s_list	*cmd;
}				t_pipex;

typedef int		t_bool;


/////////////////////////////engine
void	ft_init_pipe(int argc, char**argv);
void	ft_init_heredoc(int argc, char**argv);
char	*ft_find_user(char **envp);

int	**ft_make_pipe(int cnt);


////////////////////////////parsing


//////////////////////////////util

void	test_str(char *type, char *str);
void	test_str2(char *type, char **str);
void	test_list(char *type, t_list *list);
void	test_spot(char	*str);
void	test_int(char *type, int num);

void	ft_free(void *memory);
t_bool	ft_malloc(void *target, int size);
int		ft_close(int fd);

t_list	*ft_listnew(char *str);
void	ft_listadd_tail(t_list **list, t_list **new);
void	ft_listdelone(t_list **list);
void	ft_listclear(t_list **list);
t_list	*ft_list_next(t_list *list, int n);

char	*ft_strndup(const char *s, int len);
void	*ft_memcpy(void *dst, const void *src, int n);
char	**ft_split(char const *s, char c);

int	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);

int	ft_putchar_fd(char c, int fd, char *color);
int	ft_putstr_fd(char *s, int fd, char *color);
int	ft_putnbr_fd(int n, int fd, char *color);



#endif

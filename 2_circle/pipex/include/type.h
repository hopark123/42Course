#ifndef TYPE_H
# define TYPE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define SUCCESS	1
# define FAIL		-1
# define ERROR		0
# define NULLPTR	0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX  10240
# endif

typedef struct s_list
{
	char			*str;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_pipex
{
	int				pip[2];
	int				out;
	char			**envp;
	char			*home;
	struct s_list	*cmd;
}				t_pipex;

typedef int			t_bool;

#endif

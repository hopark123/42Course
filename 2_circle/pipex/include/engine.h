#ifndef ENGINE_H
# define ENGINE_H

int			ft_execve(t_pipex *pipex, int *t_pip, int index);
char		*ft_find_user(char **envp);
void		ft_redirect(t_pipex *pipex, int argc, char**argv);
void		ft_heredoc(t_pipex *pipex, int argc, char**argv);
int			ft_run_pipex(t_pipex *pipex);

#endif
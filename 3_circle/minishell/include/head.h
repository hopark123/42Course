#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>



void	ft_putchar_fd(char c, int fd, char *color);
void	ft_putstr_fd(char *s, int fd, char *color);
void	ft_putnbr_fd(int n, int fd, char *color);

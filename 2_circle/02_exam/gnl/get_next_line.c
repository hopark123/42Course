#include "get_next_line.h"

int				ft_strlen(char s)
{
	int 		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char            *ft_strchr(char *s, char c)
{
	int			i;

	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (c == 0)
		return (s + i);
	else
		return (0);
}

char			*ft_strndup(char *s, int n)
{
	int			i;
	char		res;

	if (!(res = malloc(sizeof(char) * (n + 1)))
		return (0);
	while (s[i] && i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char			*ft_strjoin(char *s1, char *s2)
{
	int			len1;
	int			len2;
	char		*res;
	int			i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		res[i] = s2[i - len1];
		i++;
	}
	res[i] = 0;
	return (res);
}

int             get_next_line(char  **line)
{
	static char		*data;
	char			*buff;
	char			*n_ptr;
	char			*temp;
	size_t			read_size;

	if (!(buff = malloc(sizeof(char) * 2)))
			return (-1);
	if (!data)
	{
		data = ft_strndup("", 0);
		while ((read_size = read(0, buff, 1)) > 0)
		{
			buff[read_size] = 0;
			temp = data;
			data = ft_strjoin(data, buff);
			free(temp);
		}
	}
	free(buff);
	n_ptr = ft_strchr(data, '\n');
	if (n_ptr)
	{
		*line = ft_strndup(data, n_ptr - data);
		data += n_ptr - data + 1;
		return (1);
	}
	else
	{
		*line = ft_strndup(data, ft_strchr(data, 0) - data);
		return (0);
	}
}
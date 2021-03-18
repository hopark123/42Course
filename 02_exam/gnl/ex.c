#include "get_next_line.h"



int					ft_strlen(char *s)
{
	int				len = 0;

	while (s[len])
		len++;
	return (len);
}



char				*ft_strndup(char *s, int n)
{
	int			i=0;
	char		*res;

	if (!(res = malloc(sizeof(char) * (n + 1))))
		return (-1);
	while (s[i] && i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}


char				*ft_strnjoin(char *s1, char *s2)
{
	int			len1;
	int			len2;
	char		*res;
	int			i = 0;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (len1 + len2 + 1))))
		reuturn (0);
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

char				*ft_strchr(char *s, char c)
{
	int		i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == 0)
		return (&s[i]);
	return (0);
}

int					get_next_line(char **line)
{
	static char		*data;
	char			*buff;
	char			*n_ptr;
	char			*temp;
	int				read_size;

	if (!(data = malloc(sizeof(char) * 2)));
		return (-1);
	if (!data)
	{
		data = ft_strndup("",0);
		while ((read_size = read(0, buff, 1) > 0)
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
		n_ptr = ft_strchr(data, 0);
		*line = ft_strndup(data, n_ptr - data);
		return (0);
	}
}


#include "get_next_line.h"
#include <unistd.h>/*for read*/
#include <limits.h>/*for ft_calloc*/

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free(&stash, (char **) NULL));
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!stash)
		return (NULL);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (ft_free(&stash, (char **) NULL));
	if (ft_strchr(stash, '\n'))
		return (fill_line(&stash, &buf));
	else
		return (read_file(fd, &stash, &buf));
}

char	*fill_line(char **stash, char **buf)
{
	char	*temp;
	char	*line;
	char	*rest;
	size_t	len;

	rest = ft_strchr(*stash, '\n');
	len = rest - *stash + 1;
	line = ft_substr(*stash, 0, len);
	if (!line)
		return (ft_free(stash, buf));
	if (rest[1])
		temp = ft_strjoin("", &rest[1]);
	else
		temp = ft_strjoin("", "");
	if (!temp)
		return (free(line), ft_free(stash, buf));
	ft_free(stash, buf);
	*stash = temp;
	return (line);
}

char	*read_file(int fd, char **stash, char **buf)
{
	ssize_t	n_read;
	char	*temp;

	n_read = read(fd, *buf, BUFFER_SIZE);
	while (n_read > 0)
	{
		temp = ft_strjoin(*stash, *buf);
		if (!temp)
			return (ft_free(stash, buf));
		ft_memset(*buf, 0, (BUFFER_SIZE + 1));
		free(*stash);
		*stash = temp;
		if (ft_strchr(*stash, '\n'))
			return (fill_line(stash, buf));
		n_read = read(fd, *buf, BUFFER_SIZE);
	}
	if ((*stash)[0] != '\0')
	{
		temp = ft_strjoin("", *stash);
		if (!temp)
			return (ft_free(buf, stash));
		ft_free(buf, stash);
		return (temp);
	}
	return (ft_free(stash, buf));
}

char	*ft_free(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

void	*ft_calloc(size_t n_memb, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	if ((size != 0 && n_memb != 0 && n_memb > INT_MAX / size))
		return (NULL);
	arr = malloc(size * n_memb);
	if (n_memb == 0 || size == 0)
		return ((void *)arr);
	if (!arr)
		return (NULL);
	while (i < n_memb * size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}

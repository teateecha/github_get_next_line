
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif/*BUFFER_SIZE*/

# include <stdio.h> /*for ssize_t*/
# include <stdlib.h> /*for malloc*/

char	*get_next_line(int fd);
char	*fill_line(char **stash, char **buf);
char	*read_file(int fd, char **stash, char **buf);
char	*ft_free(char **s1, char **s2);
void	*ft_calloc(size_t n_memb, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memset(void *s, int c, size_t n);
#endif/*GET_NEXT_LINE.H*/

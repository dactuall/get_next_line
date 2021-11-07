#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
#define BUFF_SIZE 35

int	get_next_line(int	fd, char	**line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int	c);
size_t	ft_strlen(const char	*s);
char	*ft_strdup(char	*src);
char	*ft_strcpy(char	*dst, char	*src);
void	ft_strclr(char	*s);

#endif

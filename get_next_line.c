#include "get_next_line.h"

char	*check_remainder(char	*remainder, char	**line)
{
	char	*p_n;

	p_n = NULL;
	if (remainder)
	{
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++p_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			ft_strclr(remainder);
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int	get_next_line(int	fd, char	**line)
{
	char		buf[BUFF_SIZE + 1];
	int		byte_was_read;
	char		*p_n;
	static char	*remainder;
	char		*tmp;

	p_n = check_remainder(remainder, line);
	while (!p_n && (byte_was_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\n';
			p_n++;
			remainder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (byte_was_read || ft_strlen(remainder)) ? 1 : 0;
}

int	main(void)
{
	char	*line;
	int	fd;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s\n\n", line);
}

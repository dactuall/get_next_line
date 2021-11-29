/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dactuall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:43:01 by dactuall          #+#    #+#             */
/*   Updated: 2021/11/29 18:53:11 by dactuall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*rem[256];
	char		*buff;
	int			read_byte;

	buff = NULL;
	if ((read(fd, buff, 0) < 0) || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_byte = read(fd, buff, BUFFER_SIZE);
	while (read_byte > 0)
	{
		buff[read_byte] = '\0';
		rem[fd] = save(buff, rem[fd]);
		if (ft_strchr(buff, '\n'))
			break ;
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte < 0)
			return (NULL);
	}
	free(buff);
	return (create_rem(&rem[fd]));
}

char	*save(char	*buff, char	*rem)
{
	char	*tmp;

	if (rem)
	{
		tmp = rem;
		rem = ft_strjoin(rem, buff);
		free(tmp);
	}
	else
		rem = ft_strdup(buff);
	return (rem);
}

char	*ft_strchr(const char	*s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

char	*create_rem(char	**rem)
{
	size_t	i;
	char	*tmp;
	char	*line;

	if (!(*rem))
		return (NULL);
	i = 0;
	while ((*rem)[i] != '\n' && (*rem)[i])
		i++;
	if (i < ft_strlen(*rem))
	{
		tmp = *rem;
		line = ft_substr(*rem, 0, ++i);
		*rem = ft_substr(*rem, i, ft_strlen(*rem));
		free(tmp);
	}
	else
	{
		line = *rem;
		*rem = NULL;
	}
	return (line);
}

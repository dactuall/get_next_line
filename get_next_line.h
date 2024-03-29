/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dactuall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:01:30 by dactuall          #+#    #+#             */
/*   Updated: 2021/11/29 17:51:24 by dactuall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*save(char	*buff, char	*rem);
char	*ft_strchr(const char	*s, int c);
char	*create_rem(char	**rem);

size_t	ft_strlen(const char	*s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char	*s1, const char	*s2);
char	*ft_strdup(char	*s1);
void	*ft_calloc(size_t count, size_t size);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dactuall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:58:52 by dactuall          #+#    #+#             */
/*   Updated: 2021/11/15 15:11:19 by dactuall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*res;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(len + 1);
	ft_memcpy(res, s, len);
	res[len] = '\0';
	return (res);
}

char	*ft_memcpy(char *dest, char *src, size_t	len)
{
	while (len-- > 0)
		*dest++ = *src++;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1 && s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int	c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dactuall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:43:15 by dactuall          #+#    #+#             */
/*   Updated: 2021/11/29 19:06:02 by dactuall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*subs;
	char	*p;
	size_t	len_sub;

	i = 0;
	if (!s || len <= 0 || start >= ft_strlen(s))
		return (NULL);
	p = (char *)s;
	len_sub = ft_strlen(p) - start;
	if (len_sub > len)
		len_sub = len;
	subs = ft_calloc((len_sub + 1), sizeof(char));
	if (!subs)
		return (NULL);
	while (len_sub--)
		subs[i++] = p[start++];
	return (subs);
}

char	*ft_strjoin(const char	*s1, const char	*s2)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (*s1)
		dest[i++] = *s1++;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char	*s)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (s[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	mult;
	int		i;

	mult = count * size;
	p = malloc(mult);
	if (!p)
		return (NULL);
	i = 0;
	while (mult--)
		p[i++] = 0;
	return ((void *)p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:19:03 by emkir             #+#    #+#             */
/*   Updated: 2025/09/12 12:29:34 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*ft_substr(char *s, int start, int len)
{
	char	*result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		result = NULL;
		return (result);
	}
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (stash && stash[i])
	{
		result[i] = stash[i];
		i++;
	}
	while (buffer && buffer[j])
	{
		result[i] = buffer[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_cut(char **stash)
{
	char	*line;
	char	*rest;
	int		len;

	if (!*stash || **stash == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	if (ft_strchr(*stash, '\n'))
	{
		len = (ft_strchr(*stash, '\n') - *stash + 1);
		line = ft_substr(*stash, 0, len);
		rest = ft_substr(*stash, len, ft_strlen(*stash) - len);
		free(*stash);
		*stash = rest;
	}
	else
	{
		line = ft_substr(*stash, 0, ft_strlen(*stash));
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

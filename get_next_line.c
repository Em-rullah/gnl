/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:35:51 by emkir             #+#    #+#             */
/*   Updated: 2025/09/10 13:22:34 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	update_stash(int fd, char **stash)
{
	char	*buffer;
	char	*stash_updated;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
	{
		free(buffer);
		return (-1);
	}
	buffer[bytes] = '\0';
	stash_updated = ft_strjoin(*stash, buffer);
	free(buffer);
	if (!stash_updated)
		return (-1);
	free(*stash);
	*stash = stash_updated;
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
		bytes = update_stash(fd, &stash);
	if (bytes == -1 || !stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_cut(&stash);
	return (line);
}

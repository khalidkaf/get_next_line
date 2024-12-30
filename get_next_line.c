/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:09:56 by kkafmagh          #+#    #+#             */
/*   Updated: 2024/12/23 02:14:48 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*group(int index, int index2, char *buffer)
{
	char	*tmp;
	char	*line;

	tmp = NULL;
	line = NULL;
	if (index != 0)
	{
		tmp = mytmp(buffer, index, '\n');
		line = ft_strjoin(line, tmp);
		free(tmp);
		return (line);
	}
	else if (index2 != 0)
	{
		tmp = mytmp(buffer, index2, '\0');
		line = ft_strjoin(line, tmp);
		free(tmp);
		return (line);
	}
	return (NULL);
}

char	*wrap2(char *buffer, char *line)
{
	int		index;
	int		index2;
	char	*tmp;

	index = ft_strchr(buffer, '\n');
	index2 = ft_strchr(buffer, '\0');
	tmp = NULL;
	if (index != 0)
	{
		tmp = group(index, index2, buffer);
		line = ft_strjoin(line, tmp);
		return (free(tmp), line);
	}
	else if (index2 != 0)
	{
		tmp = group(index, index2, buffer);
		line = ft_strjoin(line, tmp);
		free(tmp);
		return (line);
	}
	return (NULL);
}

char	*bufferread(int fd, char *buffer, char *line)
{
	int	ok;

	ok = read(fd, buffer, BUFFER_SIZE);
	if (!ok)
		return (line);
	buffer[ok] = 0;
	if (ok < 0)
		return (free(line), NULL);
	return (line);
}

char	*beforeread(char *buffer, char *line)
{
	int		j;
	char	*tmp;

	if (ft_strchr(buffer, '\n') != 0)
	{
		tmp = ft_strndup(buffer, ft_strchr(buffer, '\n'));
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = buffer;
		tmp = tmp + ft_strchr(buffer, '\n');
		j = -1;
		while (tmp[j++])
			buffer[j] = tmp[j];
		buffer[j] = 0;
		return (line);
	}
	else if ((ft_strchr(buffer, '\0') != 0))
	{
		tmp = ft_strndup(buffer, ft_strchr(buffer, '\0'));
		line = ft_strjoin(line, tmp);
		free(tmp);
		buffer[0] = 0;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	while (1)
	{
		if (buffer[0])
		{
			line = beforeread(buffer, line);
			if (ft_strchr(line, '\n'))
				return (line);
		}
		line = bufferread(fd, buffer, line);
		if (!buffer[0])
			return (line);
		if (ft_strchr(buffer, '\0') == 0)
			line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n') != 0)
			return (line = wrap2(buffer, line));
		else if (ft_strchr(buffer, '\0') != 0)
			line = wrap2(buffer, line);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	// while(i<10)
	{
		// line = get_next_line(fd);
		printf("Line %d : %s\n", i + 1, line);
		free(line);
		i++;

	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:52:23 by kkafmagh          #+#    #+#             */
/*   Updated: 2024/12/27 01:38:20 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (!s1 && !s2)
		return (free(str), NULL);
	while (s1 != NULL && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	free(s1);
	return (str);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == c)
		{
			return (i + 1);
		}
		i++;
	}
	return (0);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*res;

	i = 0;
	if (!n)
		return (NULL);
	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*mytmp(char *buffer, int index, char c)
{
	char	*line;
	int		j;
	char	*tmp;

	tmp = NULL;
	line = NULL;
	j = 0;
	tmp = ft_strndup(buffer, index);
	line = ft_strjoin(line, tmp);
	free(tmp);
	tmp = buffer;
	tmp = tmp + index;
	j = -1;
	if (c == '\n')
		while (tmp[j++])
			buffer[j] = tmp[j];
	else if (c == '\0')
		j = 0;
	buffer[j] = 0;
	tmp = NULL;
	return (line);
}

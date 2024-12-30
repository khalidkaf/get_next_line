/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkafmagh <kkafmagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:42:52 by kkafmagh          #+#    #+#             */
/*   Updated: 2024/12/27 01:38:15 by kkafmagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//############ GNL ################

char	*get_next_line(int fd);

//############ UTILS ################

int		ft_strlen(char *s);

char	*ft_strndup(char *str, int n);

int		ft_strchr(char *s, char c);

char	*ft_strjoin(char *s1, char *s2);

char	*mytmp(char *buffer, int index, char c);

#endif
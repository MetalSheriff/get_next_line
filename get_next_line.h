/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:20:33 by ypeckled          #+#    #+#             */
/*   Updated: 2020/12/06 18:51:34 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int							get_next_line(int fd, char **line);
char						*ft_strdup(const char *str);
size_t						ft_strlen(const char *str);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_string_search_n(char *line);
char						*ft_check_tail(char *backup);
char						*ft_check_line(const char *backup);

#endif

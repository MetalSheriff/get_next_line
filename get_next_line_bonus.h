/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:41:44 by ypeckled          #+#    #+#             */
/*   Updated: 2020/12/06 18:51:34 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:41:29 by ypeckled          #+#    #+#             */
/*   Updated: 2020/12/06 18:51:47 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_check_line(const char *backup)
{
	char	*temp;
	int		index;
	int		i;

	index = 0;
	if (backup[index] == '\n' || backup[index] == '\0')
		return (ft_strdup(""));
	else
		while (*backup && backup[index] != '\0' && backup[index] != '\n')
			index++;
	if (!(temp = malloc(sizeof(char) * (index + 1))))
		return (NULL);
	i = 0;
	while (i < index)
	{
		temp[i] = backup[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_check_tail(char *backup)
{
	char	*temp;
	int		index;
	int		i;

	index = 0;
	i = 0;
	while (backup[index] != '\n' && backup[index] != '\0')
		index++;
	if (backup[index] == '\0')
	{
		free(backup);
		return (0);
	}
	if (!(temp = malloc(sizeof(char) *
						(ft_strlen(backup) - index + 1))))
		return (NULL);
	index++;
	while (backup[index] != '\0')
		temp[i++] = backup[index++];
	temp[i] = '\0';
	free(backup);
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[15000];
	char		*buffer;
	int			bytes_were_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
		(!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	bytes_were_read = 1;
	while (!(ft_string_search_n(backup[fd])) && bytes_were_read != 0)
	{
		bytes_were_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_were_read == -1)
		{
			free(backup[fd]);
			return (-1);
		}
		buffer[bytes_were_read] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buffer);
	}
	free(buffer);
	*line = ft_check_line(backup[fd]);
	backup[fd] = ft_check_tail(backup[fd]);
	return (bytes_were_read == 0 ? 0 : 1);
}

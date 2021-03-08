/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypeckled <ypeckled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:56:26 by ypeckled          #+#    #+#             */
/*   Updated: 2020/12/01 14:56:26 by ypeckled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strdup(const char *str)
{
	unsigned int	s;
	char			*dest;
	unsigned int	d;

	s = 0;
	d = 0;
	if (!str)
		return (NULL);
	while (str[s] != '\0')
		s++;
	if (!(dest = malloc(sizeof(char) * (s + 1))))
		return (NULL);
	while (d < s)
	{
		dest[d] = str[d];
		d++;
	}
	dest[d] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*temp;

	i1 = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(temp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i1] != '\0')
	{
		temp[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != '\0')
	{
		temp[i1 + i2] = s2[i2];
		i2++;
	}
	temp[i1 + i2] = '\0';
	free((void*)s1);
	return (temp);
}

char	*ft_string_search_n(char *line)
{
	char *temp;

	if (!line)
		return (NULL);
	temp = line;
	while (*temp != '\0')
	{
		if (*temp == '\n')
		{
			return (temp);
		}
		temp++;
	}
	return (NULL);
}

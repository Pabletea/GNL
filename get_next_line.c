/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:42:48 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/14 12:46:06 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buffer(int fd, char *left_c, char *buff);
static char	*fill_line(char *line);
static char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*lefts;
	char		*line;
	char		*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(lefts);
		free(buff);
		return (NULL);
	}
	if (!buff)
		return (NULL);
	line = fill_buffer(fd, lefts, buff);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	lefts = fill_line(line);
	return (line);
}

static char	*fill_line(char *line_buff)
{
	char	*lefts;
	ssize_t	i;

	i = 0;
	while (line_buff[i] != '\n' && line_buff[i] != '\0')
		i++;
	if (line_buff[i] == 0 )
		return (NULL);
	lefts = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i);
	if (*lefts == 0)
	{
		free(lefts);
		lefts = NULL;
	}
	line_buff[i + 1] = 0;
	return (lefts);
}

static char	*fill_buffer(int fd, char *lefts, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;
	
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!lefts)
			lefts = ft_strdup("");
		temp = lefts;
		lefts = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (lefts);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
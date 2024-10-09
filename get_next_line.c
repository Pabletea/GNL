/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:36:59 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/09 12:43:43 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_buffer(void)
{
	static char	*lb1;

	
	return (lb1);
}

char	*set_line(char *lb1)
{
	return (lb1);
}

char	*get_next_line(int fd)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!fd || fd < 0 ||)
	{
		
	}
	
	if (!buff)
		return (NULL);
	if (fd == -1)
		return (NULL);
	else
		while (read(fd, buff, BUFFER_SIZE) > 0)
		{
			if (*buff == '\n')
				break ;
		}
	return (buff);
}

int	main(void)
{
	int		fd;
	char	*res;
	int		i;

	fd = open("../test.txt", O_RDONLY);
	res = get_next_line(fd);
	if (res)
	{
		i = 0;
		while (res[i] != '\0')
		{
			write(1, &res[i], 1);
			i++;
		}
	}
	return (0);
}

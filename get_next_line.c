/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:36:59 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/09 14:23:46 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	
static char	*fill_line(int fd, char *lefts, char *buff )
{
	int	check;
	char	*tmp;
	
	check = 1;

	while (check > 1)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if(check == -1)
		{
			free(lefts);
			return (NULL);
		}
		else if (check == 0)
			break;
		buff[check] = 0;
		
	}

	
	
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char *lefts;
	char	*res_line;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(lefts);
		free(buff);
		return NULL;
	}
	if (!buff)
		return (NULL);
	res_line =  fill_line(fd, lefts , buff);
	free(buff);
	buff = NULL;
	if (!res_line)
		return (NULL);
	return (res_line);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:18:53 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/27 18:18:32 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include "get_next_line.h" 

char *ft_get(int fd,char *str)
{
	char *buf;
	int count;

	buf = malloc(BUFFER_SIZE);
	int i = 0;
	int n = 1;
	while (n)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count <= 0)
			return 0;
		str = ft_strjoin(str,buf);
		while (str[i])
		{
			if (str[i++] == '\n')
			{
				n = 0;
				break;
			}
		}
	}
	free(buf);
	return (str);
}

char *ft_get_line(char *str)
{
	if (!str)
		return (0);
	int i;
	char *line;

	i = 0;
	while (str[i] != '\n')
		i++;
	line = malloc(i);
	i = 0;
	if (!line)
		return (0);
	while (str[i])
	{
		line[i] = str[i];
		if (str[i] == '\n')
			break;
		i++;
	}
	free(str);
	line[++i] = '\0';
	return(line);
}

char *ft_back_up(char *str)
{
	if (!str)
		return (0);
	int i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	
	return (str + i);
}

char *get_next_line(int fd)
{

	if (fd <  0 || BUFFER_SIZE <= 0)
		return (0);
	static char *stack = "";
	char *line = "";

	if (!stack)
		return (0);
	line = ft_memcpy(line, stack, ft_strlen(stack));
	stack = ft_get(fd,stack);
	line = ft_get_line(stack);
	stack = ft_back_up(stack);
	
	return (stack);
}
int main()
{
	int fd;
	fd = open("line.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
//	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
//	
	close(fd);
}

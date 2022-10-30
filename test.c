/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:49:49 by mzeroual          #+#    #+#             */
/*   Updated: 2022/10/28 19:53:09 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_extract(int fd,char *buffer, char *backup)
{
    int read_line;
    // int k;
    char *temp;
    read_line = 1;
    while(read_line != 0)
    {
        read_line = read(fd,buffer,BUFFER_SIZE);
        if(read_line <= 0)
            break;
        buffer[read_line] = '\0';
        if(!backup)
            backup = ft_strdup("");
        temp = backup;
        backup = ft_strjoin(temp,buffer);
        free(temp);
        // k = gm_strchr(buffer, '\n');
        if(ft_strchr(buffer, '\n'))
            break;
    }
    return backup;
}
char *ft_extract_backup(char *line)
{
    size_t i;
    char *backup;

    i = 0;
    while(line[i] != '\n' && line[i] != '\0')
        i++;
    if(line[i] == 0 || line[1] == 0)
        return 0;
    backup = ft_substr(line, i + 1,ft_strlen(line) - i);
    if(*backup)
    {
        free(backup);
        return 0;
    }
    line[i + 1] = '\0';
    return backup;
}
char *get_next_line(fd)
{
    char *line;
    static char *backup;
    char *buffer;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return 0;
    buffer = (char *)malloc(sizeof(char ) * BUFFER_SIZE + 1);
    if(!buffer)
        return 0;
    line = ft_extract(fd,buffer,backup);
    free(buffer);
    if(!line)
        return 0;
    backup = ft_extract_backup(line);

    return line;
}


int main()
{
	int fd;
	fd = open("line.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	
	close(fd);

}

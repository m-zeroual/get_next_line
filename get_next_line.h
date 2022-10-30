#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H



#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include <stdlib.h>
// #include "Memd/mem.h"

char    *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);
int     gm_strchr(const char *str, int c);


#endif

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
size_t			ft_strlen(char *s);
int				get_next_line(int fd, char **line);
char            *ft_strdup(char *src);

# endif
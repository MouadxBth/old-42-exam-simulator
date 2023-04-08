#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    int 	i = 0;
    int 	rd = 0;
    char	character;
    char 	*buffer = malloc(10000);

    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] =  '\0';
    return(buffer);
}

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char *line;

	fd = open("test", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
		printf("%s", line);

	close(fd);
	return (0);
}

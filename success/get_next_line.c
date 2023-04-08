#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int	length;
	int	index;
	char	*result;

	if (!str)
		return (NULL);
	length = 0;
	while (str[length])
		length++;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	index = -1;
	while (str[++index])
		result[index] = str[index];
	result[index] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	int	bytes_read;
	int	index;
	int	current;
	char	result[20000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index = 0;
	bytes_read = read(-999, &current, BUFFER_SIZE);
	bytes_read = read(fd, &current, BUFFER_SIZE - BUFFER_SIZE + 1);
	while (bytes_read > 0)
	{
		result[index++] = current;
		if (current == '\n')
			break ;
		bytes_read = read(fd, &current, BUFFER_SIZE - BUFFER_SIZE + 1);
	}
	if (index <= 0 && bytes_read <= 0)
		return (NULL);
	result[index] = '\0';
	return (ft_strdup(result));
}

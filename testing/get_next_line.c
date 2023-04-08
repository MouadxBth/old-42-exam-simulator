/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:10:13 by mbouthai          #+#    #+#             */
/*   Updated: 2022/12/28 15:08:29 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (!src)
		return (0);
	if (size > 0)
	{
		index = -1;
		while (src[++index] && index < (size - 1))
			dst[index] = src[index];
		dst[index] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	index;

	if (!dst)
		return (0);
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (size <= dst_length)
		return (size + src_length);
	index = 0;
	while (src && src[index] && index < (size - dst_length - 1))
	{
		dst[dst_length + index] = src[index];
		index++;
	}
	dst[dst_length + index] = '\0';
	return (dst_length + src_length);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start > str_len)
		start = str_len;
	if (len > str_len - start)
		len = str_len - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str + start, len + 1);
	if (!*result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	if (s1)
		ft_strlcpy(result, s1, s1_len + 1);
	else
		result[0] = '\0';
	if (s2)
		ft_strlcat(result, s2, s1_len + s2_len + 1);
	if (!*result)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	free(s1);
	return (result);
}


int	ft_find(char c, char *str)
{
	int	index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	if (!c && !str[index])
		return (index);
	return (-1);
}

char	*ft_fill_stash(int fd, char *stash, int *new_line)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		*new_line = ft_find('\n', stash);
		if (*new_line >= 0)
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_extract_line(char *stash, int new_line)
{
	char	*line;
	char	*temp;

	if (!stash)
		return (NULL);
	if (new_line >= 0)
	{
		temp = ft_substr(stash, 0, new_line + 1);
		line = ft_strjoin(NULL, temp);
		free(temp);
	}
	else
		line = ft_strjoin(NULL, stash);
	return (line);
}

char	*ft_process_stash(char *stash, int new_line)
{
	char	*temp;

	if (!stash)
		return (NULL);
	if (new_line < 0)
	{
		free(stash);
		return (NULL);
	}
	temp = ft_substr(stash, new_line + 1, ft_strlen(stash));
	free(stash);
	stash = temp;
	return (stash);
}	

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_fill_stash(fd, stash, &new_line);
	if (!stash)
		return (NULL);
	if (!*stash)
	{
		free(stash);
		return (NULL);
	}
	line = ft_extract_line(stash, new_line);
	stash = ft_process_stash(stash, new_line);
	return (line);
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

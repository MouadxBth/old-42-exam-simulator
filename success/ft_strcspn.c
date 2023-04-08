#include <stdio.h>
#include <string.h>

int	ft_strchr(const char *str, int c)
{
	int	index;

	if (!str)
	{
		if (!c)
			return (1);
		return (0);
	}
	index = -1;
	while (str[++index])
		if (str[index] == c)
			return (1);
	return (0);
}

size_t  ft_strcspn(const char *str, const char *reject)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index] && str[index] != ' ')
	{
		if (ft_strchr(reject, str[index]))
			break ;
		index++;
	}
	return (index);
}

#include <unistd.h>

int	ft_isalpha(int c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

char	rotate(int c)
{
	if (ft_isalpha(c))
	{
		if (c == 'z')
		       return ('a');
		else if (c == 'Z')
			return ('A');
		return (c + 1);
	}	
	return (c);
}

void	ft_rotone(char *str)
{
	int	index;

	if (!str)
		return ;
	index = 0;
	while (str[index])
	{
		ft_putchar(rotate(str[index]));
		index++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_rotone(argv[1]);
	ft_putchar('\n');
	return (0);
}

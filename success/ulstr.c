#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	ft_isupp(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_islow(int c)
{
	return (c >= 'a' && c <= 'z');
}

void	ft_putstr(char *str)
{
	int	index;

	if (!str)
		return ;
	index = -1;
	while (str[++index])
	{
		if (ft_isupp(str[index]))
			ft_putchar(str[index] + 32);
		else if (ft_islow(str[index]))
			ft_putchar(str[index] - 32);
		else
			ft_putchar(str[index]);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr(argv[1]);
	ft_putchar('\n');
	return (0);
}

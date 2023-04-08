#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	ft_isnum(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	index;
	int	result;

	if (!str)
		return (0);
	index = 0;
	result = 0;
	while (str[index] <= 32)
		index++;
	while (ft_isnum(str[index]))
	{
		result *= 10;
		result += str[index] - '0';
		index++;
	}
	return (result);
}

void	print_hex(int n)
{
	if (n > 16)
	{
		print_hex(n / 16);
		print_hex(n % 16);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else if (n < 16)
		ft_putchar(n + 87);
}

int	main(int argc, char **argv)
{
	int	n;

	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		print_hex(n);
	}
	ft_putchar('\n');
	return (0);
}

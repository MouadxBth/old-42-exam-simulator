#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	length;

	if (!str)
		str = "(null)";
	length = -1;
	while (str[++length])
		ft_putchar(str[length]);
	return (length);
}

int	ft_putnbr(long long int number, int base)
{
	int	result;
	char	*hex = "0123456789abcdef";

	result = 0;
	if (number < 0)
	{
		number *= -1;
		result += ft_putchar('-');
	}
	if (number >= base)
		result += ft_putnbr(number / base, base);
	result += ft_putchar(hex[number % base]);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	int	result;
	int	index;
	va_list	args;

	if (!str)
		return (0);
	result = 0;
	index = -1;
	va_start(args, str);
	while (str[++index])
	{
		if (str[index] == '%' && str[index + 1])
		{
			index++;
			if (str[index] == 's')
				result += ft_putstr(va_arg(args, char *));
			else if (str[index] == 'd')
				result += ft_putnbr((long long int)va_arg(args, int), 10);
			else if (str[index] == 'x')
				result += ft_putnbr((long long int)va_arg(args, unsigned int), 16);
		}
		else
			result += ft_putchar(str[index]);
	}
	return (va_end(args), result);
}

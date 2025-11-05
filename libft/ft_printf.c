/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:03:05 by hnogi             #+#    #+#             */
/*   Updated: 2025/10/05 14:33:56 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	process_format(const char format, va_list args)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		length += print_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += print_decimal(va_arg(args, int));
	else if (format == 'u')
		length += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		length += print_percent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += process_format(str[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

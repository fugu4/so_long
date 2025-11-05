/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:40:04 by hnogi             #+#    #+#             */
/*   Updated: 2025/10/05 14:34:06 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	print_hex(unsigned int num, const char format)
{
	char	*str;
	int		len;

	str = utoa_base((unsigned long long)num, 16);
	if (!str)
		return (0);
	if (format == 'X')
		str = strtoupper(str);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	print_pointer(unsigned long long ptr)
{
	char	*str;
	int		len;

	if (ptr == 0)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	str = utoa_base(ptr, 16);
	if (!str)
		return (0);
	write(1, "0x", 2);
	len = ft_strlen(str);
	write(1, str, len);
	len += 2;
	free(str);
	return (len);
}

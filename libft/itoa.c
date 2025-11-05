/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:14:07 by hnogi             #+#    #+#             */
/*   Updated: 2025/10/05 14:34:11 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen_base(long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*itoa_base(long long n, int base)
{
	char				*str;
	int					len;
	unsigned long long	num;

	len = numlen_base(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	num = n;
	if (num == 0)
		str[0] = '0';
	len -= 1;
	while (num > 0)
	{
		str[len--] = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (str);
}

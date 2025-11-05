/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:08:03 by hnogi             #+#    #+#             */
/*   Updated: 2025/10/05 14:34:24 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	unumlen_base(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*utoa_base(unsigned long long n, int base)
{
	char	*str;
	int		len;

	len = unumlen_base(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len -= 1;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len] = "0123456789abcdef"[n % base];
		n /= base;
		len--;
	}
	return (str);
}

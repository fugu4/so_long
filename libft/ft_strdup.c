/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:18:00 by hnogi             #+#    #+#             */
/*   Updated: 2025/05/06 16:41:42 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*buf;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	while (s1[i] != '\0')
	{
		buf[i] = s1[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

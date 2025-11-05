/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:18:40 by hnogi             #+#    #+#             */
/*   Updated: 2025/05/06 20:39:01 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (c == '\0')
		return (*s != '\0');
	while (s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == c || s[i] == '\0')
			count++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**free_memory(char **res, size_t i)
{
	while (i--)
		free(res[i]);
	free(res);
	return (NULL);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strcpy(char *dest, char const *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c && *s != '\0')
			s++;
		res[i] = (char *)malloc(ft_word_len(s, c) + 1);
		if (!res[i])
			return (free_memory(res, i));
		ft_strcpy(res[i], s, c);
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	res[count] = NULL;
	return (res);
}

// #include <stdio.h>

// int main(void)
// {
// 	char **result = ft_split("   I am super hero  ", ' ');
// 	int i = 0;

// 	while (result[i] != NULL)
// 	{
//     printf("%s\n", result[i]);
//     i++;
// 	}
// }

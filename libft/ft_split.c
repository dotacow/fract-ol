/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:28:24 by yokitane          #+#    #+#             */
/*   Updated: 2024/12/02 19:17:34 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **words, size_t reserved)
{
	size_t	i;

	i = 0;
	while (i < reserved)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!s[0] || !s)
		return (0);
	if (s[0] != c)
		count++;
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_reserve(size_t count, char **words, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (i < count)
	{
		len = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			len++;
			j++;
		}
		words[i] = ft_calloc(len + 1, sizeof(char));
		if (!words[i])
		{
			ft_free(words, count);
			return (NULL);
		}
		i++;
	}
	return (words);
}

static void	ft_fill(size_t count, char **words, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < count)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			words[i][k] = s[j];
			k++;
			j++;
		}
		words[i][k] = '\0';
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**words;

	count = ft_count_words(s, c);
	if (!count)
		return (NULL);
	words = ft_calloc(count + 1, sizeof(char *));
	if (!s || !words)
	{
		return (NULL);
	}
	if (!ft_reserve(count, words, s, c))
	{
		ft_free(words, count);
		return (NULL);
	}
	ft_fill(count, words, s, c);
	return (words);
}

// int	main(void)
// {
// 	char	**words;
// 	int		i;
// 	char	*dup;
// 	i = 0;
// 	dup = ft_strdup("Tripppppppp");
// 	words = ft_split(dup, ' ');
// 	while (words[i])
// 	{
// 		printf("%s", words[i]);
// 		printf("\n");
// 		i++;
// 	}
// 	ft_free(words, i);
// 	return (0);
// }

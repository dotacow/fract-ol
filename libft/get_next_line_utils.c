/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:34:23 by yokitane          #+#    #+#             */
/*   Updated: 2024/10/14 17:23:01 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_strdup2(char *s)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen2(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen2(s))
	{
		str[i] = (char)s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr2(char *s, int start, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(len + 1 + start);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*joined_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	joined_str = (char *)malloc(ft_strlen2(s1) + ft_strlen2(s2) + 1);
	if (!joined_str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		joined_str[i] = s1[i];
	j = 0;
	while (s2[j])
		joined_str[i++] = s2[j++];
	joined_str[i] = '\0';
	free(s1);
	return (joined_str);
}

char	*ft_cutstash(char *stash, int nlindex)
{
	char	*str;

	if (!nlindex)
	{
		free(stash);
		return (NULL);
	}
	str = ft_strdup2(stash + nlindex);
	if (!str)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	return (str);
}

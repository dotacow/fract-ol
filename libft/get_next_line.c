/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:50:37 by yokitane          #+#    #+#             */
/*   Updated: 2024/10/14 17:22:48 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

static char	*ft_free(char *str1)
{
	if (str1)
		free(str1);
	return (NULL);
}

static char	*ft_strchr(char *s, int c)
{
	char	*rtr;
	char	p;

	p = c;
	rtr = s;
	while (*rtr)
	{
		if (*rtr == p)
			return (rtr);
		rtr++;
	}
	if (*rtr == p)
		return (rtr);
	return (NULL);
}

static char	*fill_stash(int fd, char *buffer, char *stash)
{
	int	byte;

	while (!ft_strchr(stash, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (free(stash), ft_free(buffer));
		if (byte == 0)
			break ;
		buffer[byte] = '\0';
		stash = ft_strjoin2(stash, buffer);
		if (!stash)
			return (ft_free(buffer));
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;
	int			nlindex;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, 1);
	stash = fill_stash(fd, buffer, stash);
	if (!stash)
		return (ft_free(stash));
	free(buffer);
	nlindex = 0;
	while (stash[nlindex] && stash[nlindex] != '\n')
		nlindex++;
	if (stash[nlindex])
		nlindex++;
	line = ft_substr2(stash, 0, nlindex);
	stash = ft_cutstash(stash, nlindex);
	if (!stash)
		return (ft_free(line));
	return (line);
}

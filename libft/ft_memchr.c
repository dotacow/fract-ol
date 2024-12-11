/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:37:19 by yokitane          #+#    #+#             */
/*   Updated: 2024/08/30 17:55:55 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*rtr;

	i = 0;
	rtr = (unsigned char *)s;
	while (i < n)
	{
		if (rtr[i] == (unsigned char)c)
			return (&rtr[i]);
		i++;
	}
	return (NULL);
}

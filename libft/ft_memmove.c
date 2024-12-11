/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:01:37 by yokitane          #+#    #+#             */
/*   Updated: 2024/08/30 15:33:25 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmpdest;
	const unsigned char	*tmpsrc;

	if (!dest && !src)
		return (dest);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	tmpdest = dest;
	tmpsrc = src;
	while (n--)
		tmpdest[n] = tmpsrc[n];
	return (dest);
}

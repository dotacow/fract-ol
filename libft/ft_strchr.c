/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:08:02 by yokitane          #+#    #+#             */
/*   Updated: 2024/08/30 15:43:20 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*rtr;
	char	p;

	p = (char)c;
	rtr = (char *)s;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:43:38 by yokitane          #+#    #+#             */
/*   Updated: 2024/08/30 16:51:25 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	*rtr;
	int		len;

	len = ft_strlen(s) + 1;
	rtr = NULL;
	temp = (char *)s;
	while (len--)
	{
		if (*temp == (char)c)
			rtr = temp;
		temp++;
	}
	return (rtr);
}

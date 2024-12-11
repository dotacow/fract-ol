/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:51:28 by yokitane          #+#    #+#             */
/*   Updated: 2024/09/08 11:45:57 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	char	*bigtmp;
	size_t	i;

	i = 0;
	bigtmp = (char *)big;
	if (lit[0] == '\0' || big == lit)
		return (bigtmp);
	if (len == 0)
		return (NULL);
	if (ft_strlen(lit) > len && big[0] != '\0')
		return (NULL);
	while (*bigtmp && (i <= (len - ft_strlen(lit))))
	{
		if (ft_strncmp(bigtmp, lit, ft_strlen(lit)) == 0)
			return (bigtmp);
		bigtmp++;
		i++;
	}
	return (NULL);
}

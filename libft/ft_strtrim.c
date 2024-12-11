/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:29:08 by yokitane          #+#    #+#             */
/*   Updated: 2024/09/02 09:30:47 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	first;
	size_t			last;
	char			*str;

	first = 0;
	last = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (first <= ft_strlen(s1) && ft_strchr(set, s1[first]))
		first++;
	while (last > first && ft_strchr(set, s1[last - 1]))
		last--;
	str = ft_substr(s1, first, last - (size_t)first);
	return (str);
}

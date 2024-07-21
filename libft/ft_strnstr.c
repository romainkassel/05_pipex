/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:03:35 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/23 16:27:45 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	i = 0;
	k = 0;
	while (haystack[i] && ((i + k) < len))
	{
		if (haystack[i + k] == needle[k])
		{
			if (needle[k + 1] == '\0')
				return ((char *)haystack + i);
			k++;
		}
		else
		{
			i++;
			k = 0;
		}
	}
	return (NULL);
}

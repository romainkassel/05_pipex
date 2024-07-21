/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:02:25 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/23 16:37:29 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	int		i;

	lensrc = ft_strlen(src);
	if (dstsize == (size_t)-1)
		dstsize = lensrc + 1;
	if (dstsize == 0)
		return (lensrc);
	i = 0;
	dstsize--;
	while (dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (lensrc);
}

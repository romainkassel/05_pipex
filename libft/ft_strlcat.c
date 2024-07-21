/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:02:12 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/23 15:09:02 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		lsrc;
	size_t	ldst;
	size_t	tlen;
	int		i;

	lsrc = ft_strlen((char *)src);
	ldst = ft_strlen(dst);
	tlen = ldst + lsrc;
	if (!dst || !src || dstsize == 0)
		return (lsrc);
	if (ldst >= dstsize)
		return (dstsize + lsrc);
	i = 0;
	while (src[i] && ldst < dstsize - 1)
	{
		dst[ldst] = src[i];
		i++;
		ldst++;
	}
	dst[ldst] = '\0';
	return (tlen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:58:41 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/14 16:09:41 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	if (src2 < dst2)
	{
		while (len-- > 0)
			dst2[len] = src2[len];
	}
	else
	{
		while (len > i)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:57:21 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/23 16:31:34 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	if (n == 0)
		return (NULL);
	str = (unsigned char *)s;
	i = 0;
	n--;
	while (n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
		n--;
	}
	if (str[i] == (unsigned char)c)
		return (str + i);
	return (NULL);
}

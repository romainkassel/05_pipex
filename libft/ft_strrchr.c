/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:03:59 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/23 15:06:11 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = ft_strlen(str);
	if (str[i] == c)
		return (str + i);
	while (i > 0)
	{
		if (str[i] == (char)c)
			return (str + i);
		i--;
	}
	if (str[i] == (char)c)
		return (str + i);
	return (NULL);
}

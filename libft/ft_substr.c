/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:04:33 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/24 14:05:14 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*malloced_str(const char *str, int size)
{
	char	*s;
	int		i;

	s = (char *)malloc(sizeof(char) * size);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (malloced_str("", 1));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof (char) * len + 1);
	if (!str)
		return (NULL);
	else
	{
		i = 0;
		while (s[start] && len)
		{
			str[i] = s[start];
			i++;
			start++;
			len--;
		}
		str[i] = '\0';
		return (str);
	}
}

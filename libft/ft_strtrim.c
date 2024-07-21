/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:04:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/23 16:37:29 by rkassel          ###   ########.fr       */
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

static int	check_set_char(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*fill_ptr(const char *s1, char *str, int i, int j)
{
	int	k;

	k = 0;
	while (i != j)
	{
		str[k++] = s1[i];
		i++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		lens1;
	int		i;
	int		j;

	lens1 = ft_strlen(s1);
	if (ft_strlen(s1) == 0)
		return (malloced_str("", 1));
	if (ft_strlen(set) == 0)
		return (malloced_str(s1, lens1 + 1));
	i = 0;
	j = lens1;
	while (s1[i] && check_set_char(s1[i], (char *)set) && i < j - 1)
		i++;
	if (i + 1 >= j)
		return (malloced_str("", 1));
	while (s1[j - 1] && check_set_char(s1[j - 1], (char *)set))
		j--;
	str = (char *)malloc((sizeof(char)) * (lens1 - i - (lens1 - j) + 1));
	if (!str)
		return (NULL);
	else
		return (fill_ptr(s1, str, i, j));
}

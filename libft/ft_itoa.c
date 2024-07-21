/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:57:02 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/23 18:41:30 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_count(long int nb)
{
	int	count;

	count = 1;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb / 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			count;

	nb = n;
	count = ft_get_count(nb);
	str = (char *)malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	str[count--] = '\0';
	while (nb / 10)
	{
		str[count--] = nb % 10 + 48;
		nb /= 10;
	}
	str[count--] = nb + 48;
	return (str);
}

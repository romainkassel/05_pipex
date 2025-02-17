/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:59:10 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/24 13:55:45 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *dest, char *src, int read_bytes)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	if (read_bytes == -1)
		read_bytes = ft_strlen(src);
	j = 0;
	while (read_bytes--)
		dest[i++] = src[j++];
	return (dest[i] = '\0', dest);
}

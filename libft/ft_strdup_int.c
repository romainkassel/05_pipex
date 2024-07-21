/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:01:18 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/01 16:59:06 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_strdup_int(int *number)
{
	int	*new_number;

	new_number = (int *)malloc(sizeof(int));
	if (!new_number)
		return (NULL);
	*new_number = *number;
	return (new_number);
}

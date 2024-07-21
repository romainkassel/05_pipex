/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:04 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/14 10:19:41 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_double_tab(char **tab, char *lines_name)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s[i] : %s\n", lines_name, tab[i]);
		i++;
	}
}

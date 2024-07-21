/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:03:50 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/23 15:34:36 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **lst, char *lst_name, char *data_type)
{
	t_list	*node;

	ft_printf("%s\n", lst_name);
	ft_printf("-\n");
	node = *lst;
	while (node)
	{
		if (ft_strcmp(data_type, "int") == 0)
			ft_printf("%d\n", *(int *)node->cont);
		node = node->next;
	}
}

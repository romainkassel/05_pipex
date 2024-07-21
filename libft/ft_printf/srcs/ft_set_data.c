/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:28:20 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/27 13:28:23 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf	*set_data(t_printf *lst)
{
	lst->leftj = 1;
	lst->leftp = 0;
	lst->acc = 0;
	lst->diese = 0;
	lst->space = 0;
	lst->psign = 0;
	lst->width = 0;
	lst->length = 0;
	lst->modulonb = 0;
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:27:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/27 13:30:01 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_str(t_printf *lst)
{
	char	*str;

	str = va_arg(lst->args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		lst->length += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		lst->length += (ft_strlen(str));
	}
	lst->length--;
}

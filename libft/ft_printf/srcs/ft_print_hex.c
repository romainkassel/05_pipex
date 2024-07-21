/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:27:12 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/27 13:28:50 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_hex(t_printf *lst, char c)
{
	unsigned int	u;

	u = va_arg(lst->args, unsigned int);
	ft_putnbr_dec_to_hex((uintptr_t)u, lst, c);
	lst->length--;
}

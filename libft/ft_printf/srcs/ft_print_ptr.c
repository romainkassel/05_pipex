/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:27:38 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/27 13:29:44 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_ptr(t_printf *lst)
{
	void	*ptr;

	ptr = va_arg(lst->args, void *);
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		lst->length += 5;
	}
	else
	{
		write(1, "0x", 2);
		lst->length += 2;
		ft_putnbr_dec_to_hex((uintptr_t)ptr, lst, 'x');
	}
	lst->length--;
}

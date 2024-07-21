/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec_to_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:28:13 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/27 13:34:06 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_check_char(int nb, char c)
{
	if (c == 'x')
		return (nb + 87);
	else
		return (nb + 55);
}

void	ft_putnbr_dec_to_hex(uintptr_t nb, t_printf *lst, char c)
{
	if (nb > 15)
	{
		ft_putnbr_dec_to_hex(nb / 16, lst, c);
		ft_putnbr_dec_to_hex(nb % 16, lst, c);
	}
	else if (nb >= 10 && nb <= 15)
	{
		c = ft_check_char(nb, c);
		write(1, &c, 1);
		lst->length++;
	}
	else
	{
		c = nb + 48;
		write(1, &c, 1);
		lst->length++;
	}
}

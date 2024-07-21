/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:27:55 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/27 13:30:16 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_uns(unsigned int nb, t_printf *lst)
{
	char	c;

	if (nb >= 0 && nb <= 9)
	{
		c = nb + 48;
		lst->length++;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_uns(nb / 10, lst);
		ft_putnbr_uns(nb % 10, lst);
	}
}

void	ft_print_uns(t_printf *lst)
{
	unsigned int	u;

	u = va_arg(lst->args, unsigned int);
	ft_putnbr_uns(u, lst);
	lst->length--;
}

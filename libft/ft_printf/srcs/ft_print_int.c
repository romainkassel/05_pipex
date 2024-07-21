/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:27:21 by rkassel           #+#    #+#             */
/*   Updated: 2024/05/27 13:29:14 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int nb, t_printf *lst)
{
	long int	n;
	char		c;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		lst->length++;
		write(1, "-", 1);
	}
	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		lst->length++;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10, lst);
		ft_putnbr(n % 10, lst);
	}
}

void	ft_print_int(t_printf *lst)
{
	int	i;

	i = va_arg(lst->args, int);
	ft_putnbr(i, lst);
	lst->length--;
}

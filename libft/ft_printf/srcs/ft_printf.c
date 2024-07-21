/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:28:05 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/18 16:48:18 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_not_specifier(char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' && c != 'u'
		&& c != 'x' && c != 'X' && c != '%')
		return (1);
	else
		return (0);
}

void	ft_check_specifier(t_printf *lst, char c)
{
	if (c == 'c')
		ft_print_char(lst);
	else if (c == 's')
		ft_print_str(lst);
	else if (c == 'p')
		ft_print_ptr(lst);
	else if (c == 'd' || c == 'i')
		ft_print_int(lst);
	else if (c == 'u')
		ft_print_uns(lst);
	else if (c == 'x')
		ft_print_hex(lst, 'x');
	else if (c == 'X')
		ft_print_hex(lst, 'X');
	else if (c == '%')
		ft_print_perc();
}

void	ft_check_flag(t_printf *lst, char c)
{
	if (c == '-')
		lst->leftj = 1;
	else if (c == '0')
		lst->leftp = 1;
	else if (c == '.')
		lst->acc = 1;
	else if (c == '#')
		lst->diese = 1;
	else if (c == ' ')
		lst->space = 1;
	else if (c == '+')
		lst->psign = 1;
}

int	ft_printf(const char *format, ...)
{
	t_printf	*lst;
	int			i;

	if (format == NULL)
		return (-1);
	lst = (t_printf *)malloc(sizeof(t_printf));
	if (!lst)
		return (0);
	(set_data(lst), va_start(lst->args, format), i = 0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			lst->length--;
			while (ft_check_not_specifier(format[i]))
				ft_check_flag(lst, format[i++]);
			ft_check_specifier(lst, format[i++]);
		}
		else
			write(1, &format[i++], 1);
	}
	(va_end(lst->args), i += lst->length);
	return (free(lst), i);
}

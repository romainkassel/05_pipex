/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:41:26 by rkassel           #+#    #+#             */
/*   Updated: 2024/06/24 13:53:57 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// External libs

# include "../../libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_printf
{
	va_list	args;
	int		leftj;
	int		leftp;
	int		acc;
	int		diese;
	int		space;
	int		psign;
	int		width;
	int		length;
	int		modulonb;

}	t_printf;

int			ft_printf(const char *format, ...);
t_printf	*set_data(t_printf *lst);

void		ft_print_char(t_printf *lst);
void		ft_print_str(t_printf *lst);
void		ft_print_ptr(t_printf *lst);
void		ft_print_int(t_printf *lst);
void		ft_print_uns(t_printf *lst);
void		ft_print_hex(t_printf *lst, char c);
void		ft_print_perc(void);
void		ft_putnbr_dec_to_hex(uintptr_t nb, t_printf *lst, char c);

#endif

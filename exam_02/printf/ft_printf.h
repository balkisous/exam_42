/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:54:04 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/15 13:58:54 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#ifndef	FT_PRINTF_H
#define FT_PRINTF_H

typedef struct	s_type
{
	int				d;
	char			*s;
	unsigned int	x;
	int				size_arg;
	int				ret;
}			t_type;

void	ft_init(struct s_type p);
void	ft_print_hexa(unsigned int n, struct s_type *p);
void	ft_putnbr(int n);
void	ft_print_d(int d, struct s_type *p);
void	ft_print_s(char *s, struct s_type *p);
void	ft_putnbr_hexa(unsigned int n);
int		ft_hexa_leng(unsigned int n);
int		ft_stock(char c, va_list nb_arg);
int		ft_printf(const char *str, ...);
int		ft_leng_d(int n);

#endif

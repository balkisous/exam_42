/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:52:13 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/15 10:06:13 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_print_s(char *s, struct s_type *p)
{
	int i;

	i = 0;
	while(s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	p->ret += i;
}

void	ft_putnbr(int	n)
{
	(void)n;
}
int		ft_leng_d(int	n)
{
	(void)n;
}
void	ft_print_d(int d, struct s_type *p)
{
	ft_putnbr(d);
	p->ret += ft_leng_d(d);	
}

void ft_init(struct s_type p)
{
	p.d = 0;
	p.s = 0;
	p.x = 0;
	p.size_arg = 0;
	p.ret = 0;
}

int		ft_stock(char c, va_list nb_arg)
{
	struct s_type	p;
	ft_init(p);
	if (c == 'x')
	{
		p.x = va_arg(nb_arg, unsigned int);
		ft_print_hexa();
	}
	if (c == 'd')
	{
		p.d = va_arg(nb_arg, int);
		ft_print_d(p.d, &p);
	}
	if(c == 's')
	{
		p.s = va_arg(nb_arg, char *);
		ft_print_s(p.s, &p);
	}
	return(p.ret);
}
int		printf(const char	*str, ...)
{
	int		i;
	int 	ret;
	va_list	nb_arg;

	i = 0;
	ret = 0;
	va_start(nb_arg, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret += ft_stock(str[i], nb_arg);
		}
		else
		{
			write(1, &str[i], 1);
			ret++;
		}
		i++;
	}
	return (ret);
}

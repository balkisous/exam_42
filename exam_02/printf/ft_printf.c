/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:52:13 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/15 13:58:51 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexa_leng(unsigned int n)
{
	int i;

	i = 0;
	while(n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_putnbr_hexa(unsigned int n)
{
	char	*str;
	int		a;

	str = "0123456789abcdef";
	if (n / 16)
		ft_putnbr_hexa(n / 16);
	a = str[(n % 16)];
	write(1, &a, 1);
}

void	ft_print_hexa(unsigned int n, struct s_type	*p)
{
	ft_putnbr_hexa(n);
	p->ret += ft_hexa_leng(n);
}

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
	char a;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n >= 0 && n <= 9)
		{
			a = n + '0';
			write(1, &a, 1);
		}
		if (n / 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}

int		ft_leng_d(int	n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	while(n)
	{
		n /= 10;
		i++;
	}
	return (i);
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
		ft_print_hexa(p.x, &p);
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
int		ft_printf(const char	*str, ...)
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
	va_end(nb_arg);
	return (ret);
}

int main ()
{
	int a = 42;
	char *str = "coucou les gens";
	int c = 896;
	printf("%d hahaa %s lolololol %x\n", a, str, c);
	ft_printf("%d hahaa %s lolololol %x\n", a, str, c);
	return (0);
}

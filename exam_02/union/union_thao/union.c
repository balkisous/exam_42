/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:31:48 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/14 16:40:55 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_me(char c, char *str)
{
	int n = 0;

	while (str[n])
	{
		if (str[n] == c)
			return (c);
		n++;
	}
	return (0);
}

int	ft_union(char *str1, char *str2)
{
	int n = 0;
	int j = 0;
	char str3[256];

	while (str1[n])
	{
		if (!find_me(str1[n], str3))
		{
			write(1, &str1[n], 1);
			str3[j] = str1[n];
			j++;
		}
		n++;
	}
	n = 0;
	while (str2[n])
	{
		if (!find_me(str2[n], str3))
		{
			write(1, &str2[n], 1);
			str3[j] = str2[n];
			j++;
		}
		n++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

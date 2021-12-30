/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_thao.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:48:49 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/01 10:49:31 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	inter(char *str1, char *str2)
{
	int	n = 0;
	int j = 0;
	char	printed[256];
	while (str1[n])
	{
		if (find_me(str1[n], str2) && !(find_me(str1[n], printed)))
		{
			ft_putchar(str1[n]);
			printed[j] = str1[n];
			j++;
		}
		n++;
	}
	ft_putchar('\n');
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		inter(av[1], av[2]);
		return (0);
	}
	return ('\n');
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_thao.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:43:21 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/01 10:45:55 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_me(char c, char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (c);
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	int i;
	int j;
	int k;
	char s3[256];
	
	i = 0;
	k = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				if (!find_me(s1[i], s3))
				{
					write(1, &s1[i], 1);
					s3[k++] = s1[i];
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		inter(av[1], av[2]);
	}
	write(1, "\n", 1);
	return(0);
}
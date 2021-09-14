/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:59:35 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/14 16:09:12 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_union(char   *s1, char   *s2)
{
    int     i;
    int     j;
    int     l;
    int     k;
    int     interrup;
    char    str[255];
    char    exept[255];

    i = 0;
    j = 0;
    k = 0;
    l = 0;
    interrup = 0;
    while(s1[i])
        str[l++] = s1[i++];
    i = 0;
    while(s2[i])
        str[l++] = s2[i++];
    l = 0;
    i = 1;
    while (str[i])
    {
        while(str[j] && str[j] != str[i])
        {
            while(exept[k])
            {
                if (exept[k] == str[j])
                    interrup = 42;
                k++;
            }
            k = 0;
			if (interrup == 0)
				exept[l++] = str[j]; 
			j++;
			interrup = 0;
		}
		i++;
	}
	while(exept[k])
	{
		if (exept[k] == str[i - 1])
			interrup = 42;
		k++;
	}
	if (interrup == 0)
		exept[l++] = str[(i - 1)];
	exept[l] = '\0';
	l = 0;
	while (exept[l])
	{
		write(1, &exept[l], 1);
		l++;
	}
	write (1, "\n", 1);
}

int main (int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
		ft_union(argv[1], argv[2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:31:44 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/16 11:04:06 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int     find_me(char *str, char c)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == c)
            return (c);
        i++;
    }
    return(0);
}
void    ft_inter(char *s1, char *s2)
{
    int i, j, k = 0;
    char str[255];
    char final[255];

    while(s1[i])
    {
        while(s2[j])
        {
            if (s1[i] == s2[j])
            {
                if (!find_me(str, s1[i]))
                {
                    write (1, &s1[i], 1);
                    str[k++] = s1[i];
                }
            }
            j++;
        }
        j = 0;
        i++;
    }
    i , j = 0;
    /*
    k = 0;
    while (final[k])
    {
        write (1, &final[k], 1);
        k++;
    }*/
}

int main (int argc, char **argv)
{
    if (argc == 3)
        ft_inter(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:59:35 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/14 15:14:57 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
        }
    
    }
}
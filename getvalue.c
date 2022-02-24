/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvalue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:44:55 by yanthoma          #+#    #+#             */
/*   Updated: 2022/02/13 12:55:40 by yanthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*getvalue(char *av)
{
        int i = 0;
        int j = 0;
        int espace = 0;
        int taille = 0;
        char *valeur;
               while (av[espace])
               {
                       if(av[espace] == 32)
                       {
                               espace++;
                       }
                       else if (av[espace] >= '1'&& av[espace] <= '4')
                       {
                               taille++;
                               espace++;
                       }
                       else if((av[espace] < '1' && av[espace] > '4') && (av[espace] != 32))
                       {
                                return 0;
                       }
               }
        valeur = malloc(sizeof(char)*(taille + 1));
        if (!valeur)
                return (0);
        i = 0;
        while (av[i])
        {
                if (av[i] >= '1' && av[i] <= '4')
                {
                        valeur[j] = av[i];
                        j++;
                }
                i++;
        }
        j = 0;
        return (valeur);
}


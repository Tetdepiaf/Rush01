/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:49:54 by nklingsh          #+#    #+#             */
/*   Updated: 2022/02/12 16:24:55 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc,char **argv)
{
	int i = 0;
	int espace = 0;
	int taille = 0;
	char valeur[50];
	if (argc == 2)
	{
		while (argv[1][espace])
		{
			if(argv[1][espace] == 32)
			{
				espace++;
			}
			else if (argv[1][espace] >= '1'&& argv[1][espace] <= '4')
			{
				valeur[taille]=argv[1][espace];
				taille++;
				espace++;
			}
			else if((argv[1][espace] < '1'&& argv[1][espace] > '4') && (argv[1][espace] != 32))
			{
				return 0;
			}

		}
	}
	printf("%c",valeur[taille-1]);
	return 0;
}


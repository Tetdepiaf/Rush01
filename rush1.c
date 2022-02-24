/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:49:54 by nklingsh          #+#    #+#             */
/*   Updated: 2022/02/12 17:39:45 by yanthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *getvalue(char *av);

int validboard(char *valeur);

int checkangle(char *valeur);

int main(int ac,char **av)
{
	char *indextableau;
	if( ac == 2)
	{
		indextableau = getvalue(av[1]);
	}
	printf("%s",indextableau);
	if (validboard(indextableau) == 1)
	{
		printf("\n \n tableau good");
	}
	
}

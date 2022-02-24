/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:32:25 by nklingsh          #+#    #+#             */
/*   Updated: 2022/02/13 12:58:10 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int 	checkangle(int *valeur)
{
	if ((valeur[0] == 1 && valeur[15] != 1) || (valeur[0] != 1 && valeur[15] == 1))
		return 0;
	if ((valeur[7] == 1 && valeur[8] != 1) || (valeur[7] != 1 && valeur[8] == 1))
		return 0;
	if ((valeur[3] == 1 && valeur[4] != 1) || (valeur[3] != 1 && valeur[4] == 1))
		return 0;
	if ((valeur[11] == 1 && valeur[12] != 1) || (valeur[11] != 1 && valeur[12] == 1))
		return 0;
	return 1;
}


int	validboard(int *valeur)
{
	int	i = 0;
	int	y = 11;
	int 	x = 15;
	while ( i<4)
	{		
		if (!(valeur[i] + valeur[y] >= '3' && valeur[i] + valeur[y] <= '5'))
			return  0;
		i++;
		y--;
	}
	while ( i<8)
	{
		if (!(valeur[i] + valeur[x] >= '3' && valeur[i] + valeur[x] <= '5'))
			return 0;
		i++;
		x--;
	}
	if( checkangle(valeur) == 1)
		return 1;
	else 
		return 0;
}










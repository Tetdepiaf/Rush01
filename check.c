/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:44:51 by nklingsh          #+#    #+#             */
/*   Updated: 2022/02/12 23:05:17 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




int	*possiblecell(int *gameboard,int *valeur,int *tab)
{
	int i = 0;
	char *possiblecell;
	char collumn1;
	char collumn2;
	char ligne1;
	char ligne2;
	while(gameboard[i] != 0)
	{
		i++;
	}
	if(gameboard[i] == 0)
	{
	//collumn and ligne2foufou
		if(i % 4 == 0)
		{
			collumn1 = tab[0];
			collumn2 = tab[11];
		}
		if(i % 4 == 1)
		{
			collumn1 = tab[1];
			collumn2 = tab[10];

		}
		if(i % 4 == 2)
		{
			collumn1 = tab[2];
			collumn2 = tab[9];
		}
		if(i % 4 == 3)
		{
			collumn1 = tab[3];
			collumn2 = tab[8];
		}
		if(i>=0 && i<=3)
		{
			ligne1 = tab[15];
			ligne2 = tab[4];
		}
		if(i>=4 && i<=7)
                {
                        ligne1 = tab[14];
                        ligne2 = tab[5];
                }
                if(i>=8 && i<=11)
                {
                        ligne1 = tab[13];
                        ligne2 = tab[6];
                }
                if(i>=12 && i<=15)
                {
                        ligne1 = tab[12];
                        ligne2 = tab[7];
                }
	}
	//outerboard
	if((i >= 0 && i<= 3) || (i % 4 == 0) || (i % 4 == 3) || (i >= 12 && i <= 15))
	{	
		if(ligne1 == 4 && ligne2 == 1)
		{
			possiblecell = {4}














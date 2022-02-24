/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:28:40 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/12 20:24:33 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*temp(int *res, int *a, int i) /*renvoie les 4 valeurs de la ligne en face de la contrainte n*/
{
	int	j;
	
	j = -1;
	if (i <= 3)
		while (++j < 4)
			a[j] = res[i + j*4];
	else if (i >= 4 && i <= 7)
		while (++j < 4)
			a[j] = res[(i - 4) + 12 - j*4];
	else if (i >= 8 && i <= 11)
		while (++j < 4)
			a[j] = res[(i - 8) * 4 + j];
	else
		while (++j < 4)
			a[j] = res[(3 + (i - 12) * 4) - j];
}

void	*modif(int *res, int *a, int i) /*modifie une ligne du tableau de valeurs par les valeurs de temp*/
{
	int	j;

	j = -1;
	if (i <= 3)
		while (++j < 4)
			res[i + j*4] = a[j];
	else if (i >= 4 && i <= 7)
		while (++j < 4)
			res[(i - 4) + 12 - j*4] = a[j];
	else if (i >= 8 && i <= 11)
		while (++j < 4)
			res[(i - 8) * 4 + j] = a[j];
	else
		while (++j < 4)
			res[(3 + (i - 12) * 4) - j] = a[j];
}

int	checkcontraintes(int *tab, int *nb, int i, int a)
{
	int	x;
	int	j;
	int	n;
	
	x = tab[0];
	j = -1;
	n = 1;
	while (++j < 3)
	{
		if (x < tab[j + 1])
		{
			x = tab[j + 1];
			n++;
		}
	}
	printf("nb[%d] = %d, n = %d, a = %d ", i, nb[i], n, a);
	if (n < nb[i])
		a = 1;
	n = 1;
	x = tab[3];
	while (--j >= 0)
	{
		if (x < tab[j])
		{
			x = tab[j];
			n++;
		}
	}
	if (n < nb[i+4])
		a = 1;
	printf("nb[%d] = %d, n = %d, a = %d ", i+4, nb[i+4], n, a);
	return (a);
}

int	checkcross(int *res, int *nb, int x, int i)
{
	int	a;
	int	j;
	int	*col;
	int	*row;

	a = 0;
	j = -1;
	col = malloc(sizeof(int)*4);
	row = malloc(sizeof(int)*4);
	temp(res, col, i % 4);
	temp(res, row, 8 + i / 4);
	while(++j < 4)
	{
		if ((x == col[j] || x == row[j]))
			a = 1;
	}/*
	a = checkcontraintes(col, nb, i % 4, a);
	a = checkcontraintes(row, nb, 8 + i / 4, a);*/
	printf(" \n");
	free(col);
	free(row);
	return (a);
}

int	*res_init(int *res, int *nb)
{
	int	i;
	int	j;
	int	a[4];

	i = 0;
	while (i < 16)
	{
		temp(res, a, i);
		if (nb[i] == 4)
		{
			j = 0;
			while (j < 4)
			{
				a[j] = j + 1;
				j++;
			}
			modif(res, a, i);
			i++;
		}
		if (nb[i] == 1)
		{
			a[0] = 4;
			modif(res, a, i);
		}
		i++;
	}
	i = 0;
	while (i < 16)
	{
			temp(res, a, i);
			if (nb[i] == 2 && a[3] == 4)
			{
				a[0] = 3;
				modif(res, a, i);
			}
			i++;
	}
}

int	solve(int i, int *res, int *res_temp, int *nb)
{
	int	j;
	int	a;
	int	k;
	int	arret;
	
	j = 0;
	arret = 0;
	if (res[i] == 0 && i < 16)
	{
		while(++j < 5)
		{
			if (arret = 1)
				return (1);
			
			a = 0;
			a = checkcross(res_temp, nb, j, i);
			if (a == 1 && j == 4)
			{
				printf("\n-------------------------------------\n");
				res_temp[i] = 0;
				printf("\n");
				a = 0;
				return (0);
			}
			if (a == 0)
			{
				res_temp[i] = j;
				arret = solve(i + 1, res, res_temp, nb);
			}
		}
	}
	if (res[i] != 0 && i < 15)
		arret = solve(i + 1, res, res_temp, nb);
	if (res[i] != 0 && i == 15)
	{
		k = -1;
		while (++k < 16)
			res[k] = res_temp[k];
		return 1;
	}
	else
		return 0;
}

int main(void)
{
	int nb[] = {4, 3, 2, 1,
		    1, 2, 2, 2,
	 	    4, 3, 2, 1,
	  	    1, 2, 2, 2};
	int res[] = {0, 0, 0, 0,
		     0, 0, 0, 0,
	 	     0, 0, 0, 0,
	  	     0, 0, 0, 0};
	int res_temp[] = {0, 0, 0, 0,
		     0, 0, 0, 0,
	 	     0, 0, 0, 0,
	  	     0, 0, 0, 0};
	res_init(res, nb);
	int i = -1;
	while (++i < 16)
	{
		res_temp[i] = res[i];
	}
	int a = solve(5, res, res_temp, nb);
	i = -1;
	while (++i < 16)
	{
		printf("%d", res[i]);
		if ((i+1) % 4 == 0 && i != 0)
			printf("\n");
	}
	return 0;
}

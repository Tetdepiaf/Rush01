/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:34:04 by nklingsh          #+#    #+#             */
/*   Updated: 2022/02/13 16:46:26 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_swap(int x,int y)
{
	int	temp;
	temp = x;
	x = y;
	y = temp;
}
#include <unistd.h>

void permute(int a, int l, int r)
{
	int i;
	i = l;
	if (l == r)
		write(1,&a,1);
	else
	{
		while (i <= r)
		{
			ft_swap((a+1), (a+i));
			permute(a,l+1,r);
			ft_swap((a+1), (a+i));
		}
	}
}

int main()
{
	int str[] = {1,2,3,4};
	permute(4,0,3);
	return 0 ;
}

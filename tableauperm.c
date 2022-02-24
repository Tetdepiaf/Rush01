/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableauperm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:18:13 by yanthoma          #+#    #+#             */
/*   Updated: 2022/02/13 17:56:06 by yanthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <string.h> 
void swap(char *a, char *b) 
{ 
    char temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void permutations(char *a, int l, int r) 
{ 
   int i; 
   if (l == r) 
     printf("%s\n", a); 
   else 
   { 	i = l;
       while (i <= r) 
       { 
          swap((a+l), (a+i)); 
          permutations(a, l+1, r); 
          swap((a+l), (a+i));
	 i++; 
       } 
   } 
} 
int main() 
{ 
    char a[] = "1234"; 
    permutations(a, 0, 3); 
    return 0; 
} 

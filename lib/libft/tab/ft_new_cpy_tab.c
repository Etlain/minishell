/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_cpy_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:11:06 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/14 19:44:05 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_new_cpy_tab(char **src)
{
	char 	**tab;
	int		i;
	int		lgt;

	lgt = 0;
	while (src[lgt] != NULL)
		lgt++;
	tab = (char **)malloc(sizeof(char *) * lgt + 1);
	i = 0;
	while (src[i] != NULL)
	{
		tab[i] = (char *)malloc(sizeof(char) * ft_strlen(src[i]));
		ft_strcpy(tab[i], src[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

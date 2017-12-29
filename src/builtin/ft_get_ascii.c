/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:59:03 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/29 19:25:57 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char ft_get_c(char ascii, int *i)
{
	char c;

	c = ascii;
	(*i) += 2;
	return (c);
}

static int	get_ascii_octal(char *word, int *ret)
{
	char	*str;
	int		i;
	int		lgt;
	int		nbr;

	lgt = 0;
	nbr = 0;
	while (ft_isdigit(word[lgt]) && word[lgt] < '8' && lgt < 3)
		lgt++;
	if (lgt == 0)
	{
		*ret = lgt;
		return (-1);
	}
	i = 0;
	while (i < lgt)
	{
		nbr += (word[i] - '0') * ft_power(8, (lgt - 1) - i);
		i++;
	}
	*ret = lgt;
	return (nbr);
}

char	ft_get_ascii(char* word, int b, int *ret)
{
	char	c;
	int		i;

	//str = "abfnrtv";
	i = 0;
	c = word[i];
	if (b == 1 && word[i] == '\\')
	{
		if (word[i + 1] != '\0')
		{	
			// cas 1 abfnrtv envoyer ascii de la chaine plus
			if (word[i + 1] == 'a')
				c = ft_get_c('\a', &i);
			else if (word[i + 1] == 'b')
				c = ft_get_c('\b', &i);
			else if (word[i + 1] == 'f')
				c = ft_get_c('\f', &i);
			else if (word[i + 1] == 'n')
				c = ft_get_c('\n', &i);
			else if (word[i + 1] == 'r')
				c = ft_get_c('\r', &i);
			else if (word[i + 1] == 't')
				c = ft_get_c('\t', &i);
			else if (word[i + 1] == 'v')
				c = ft_get_c('\v', &i);
			else if (word[i + 1] == '\\')
				c = ft_get_c('\\', &i);
			// c (on ignore la suite de la chaine y compris les \n de fin)
			else if (word[i + 1] == 'c')
			{
				*ret = -1;
				return ('\0');
			}
			// nombre octale plus petit ou egale a 0777
			else if (word[i + 1] == '0')
			{
				c = get_ascii_octal(&word[i + 2], ret);
				*ret += 2;
				return (c);
			}
		}
	}
	*ret = i;
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 20:59:03 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/13 15:31:15 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static wchar_t			ft_get_c(char ascii, int *i)
{
	char c;

	c = ascii;
	(*i) += 2;
	return (c);
}

static unsigned char	get_ascii_octal(char *word, int *ret)
{
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

static wchar_t			ft_get_ascii_1(char *word, int *i, int *ret)
{
	if (word[*i + 1] == 'a')
		return (ft_get_c('\a', i));
	else if (word[*i + 1] == 'b')
		return (ft_get_c('\b', i));
	else if (word[*i + 1] == 'f')
		return (ft_get_c('\f', i));
	else if (word[*i + 1] == 'n')
		return (ft_get_c('\n', i));
	else if (word[*i + 1] == 'r')
		return (ft_get_c('\r', i));
	else if (word[*i + 1] == 't')
		return (ft_get_c('\t', i));
	else if (word[*i + 1] == 'v')
		return (ft_get_c('\v', i));
	else if (word[*i + 1] == '\\')
		return (ft_get_c('\\', i));
	else if (word[*i + 1] == 'c')
	{
		*ret = -1;
		return ('\0');
	}
	return (0);
}

wchar_t					ft_get_ascii(char *word, int b, int *ret)
{
	wchar_t	c;
	wchar_t	tmp;
	int		i;

	i = 0;
	c = word[i];
	if (b == 1 && word[i] == '\\')
	{
		if (word[i + 1] != '\0')
		{
			if ((tmp = ft_get_ascii_1(word, &i, ret)) != 0)
				c = tmp;
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

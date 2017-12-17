/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:06:19 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/17 21:30:10 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
# define BUF_ECHO 5

static void	ft_putbuf(char **buf, int *buf_lgt)
{
	//ft_putendl("see");
	ft_putstr(*buf); // put buf and bzero and lgt = 0
	*buf_lgt = 0;
	ft_bzero(*buf, BUF_ECHO);
}


static void	ft_see_word(char *word, char **buf, int *buf_lgt, int *b)
{
	int i;

	i = 0;
/*	while (i < BUF_ECHO)
	{
		(*buf)[i] = 'b';
		ft_putendl(*buf);
		i++;
	}*/
	//ft_putendl(word);
	while (word[i] != '\0')
	{
		if (word[i] == '"')
			(*b == 0) ? (*b = 1) : (*b = 0);
		/*if (*b == 1 && word[i] == '\\' && word[i + 1] != '\0')
		{
			//if (word[i + 1] == 'n')
				
		}
		else
		{*/
			(*buf)[*buf_lgt] = word[i];
			(*buf_lgt)++;
		//}
		if (*buf_lgt == (BUF_ECHO - 1))
			ft_putbuf(buf, buf_lgt);
		i++;
	}
}

void	ft_echo(char *cmd)
{
	char **tab;
	char *buf;
	int j;
	int	buf_lgt;
	int	b;

	buf = (char *)ft_memalloc(sizeof(char) * BUF_ECHO);
	char *str;
	str = "je suis  je suis  dans des guillemets    g";
	tab = ft_strsplit(str, ' '); //remplacer par cmd
	//ft_putendl_tab(tab);
	buf_lgt = 0;
	j = 0;
	b = 0;
	while (tab[j] != NULL)
	{
		ft_see_word(tab[j], &buf, &buf_lgt, &b);
		j++;
		if (tab[j] != NULL)
		{
			//ft_putendl(buf);
			if (buf_lgt == (BUF_ECHO - 1))
				ft_putbuf(&buf, &buf_lgt);
			buf[buf_lgt] = ' ';
			buf_lgt++;
		}
	}
	//ft_printf("tets :%d\n", buf_lgt);
	if (buf_lgt > 0)
		ft_putbuf(&buf, &buf_lgt);
	ft_putchar('\n');
	// guillemet
	//ft_putendl(cmd);
	//free(buf);
	//ft_free_tab(tab);
}

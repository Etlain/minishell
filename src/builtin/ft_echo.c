/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:06:19 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/26 13:53:53 by mmouhssi         ###   ########.fr       */
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

static int	ft_see_word(char *word, char **buf, int *buf_lgt, int *b)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (word[i] != '\0')
	{
		if (*buf_lgt == (BUF_ECHO))
			ft_putbuf(buf, buf_lgt);
		if (word[i] == '"')
			(*b == 0) ? (*b = 1) : (*b = 0);
		else
		{
			if (*b == 0 && word[i] == '\\')
				i++;
			ret = 0;
			(*buf)[*buf_lgt] = ft_get_ascii(&word[i], *b, &ret);
			if (ret == -1)
				return (ret);
			(*buf_lgt)++;
			((*buf)[*buf_lgt] != '\0') ? (i++) : 0;
		}
		(ret > 0) ? (i += ret) : (i++);
	}
	return (0);
}

void	ft_echo(char *cmd)
{
	char **tab;
	char *buf;
	int j;
	int	buf_lgt;
	int	b;

	buf = (char *)ft_memalloc(sizeof(char) * BUF_ECHO + 1);
	char *str;
	str = cmd;
	//str = "je suis  je suis dans des guillemets    g";
	tab = ft_strsplit(str, ' '); //remplacer par cmd
	//ft_putendl_tab(tab);
	buf_lgt = 0;
	j = 0;
	b = 0;
	while (tab[j] != NULL)
	{
		if (ft_see_word(tab[j], &buf, &buf_lgt, &b) == -1)
			break;
		j++;
		if (tab[j] != NULL)
		{
			//ft_putendl(buf);
			if (buf_lgt == (BUF_ECHO))
				ft_putbuf(&buf, &buf_lgt);
			buf[buf_lgt] = ' ';
			buf_lgt++;
		}
	}
	//ft_printf("tets :%d\n", buf_lgt);
	if (buf_lgt > 0)
		ft_putbuf(&buf, &buf_lgt);
	ft_putchar('\n'); // recuperer ret -1 de ft see word
	// guillemet
	//ft_putendl(cmd);
	free(buf);
	ft_free_tab(tab);
}

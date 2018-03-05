/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:06:19 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/05 20:37:43 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
# define BUF_ECHO 6

void	ft_bwzero(void *s, size_t n)
{
	wchar_t *tab;
	size_t			i;

	i = 0;
	tab = (wchar_t*)s;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
}

static void	ft_putbuf(wchar_t **buf, int *buf_lgt)
{
	ft_putwstr(*buf);
	*buf_lgt = 0;
	ft_bwzero(*buf, BUF_ECHO);
}

static int	ft_see_word(char *word, wchar_t **buf, int *buf_lgt, int *b)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (word[i] != '\0')
	{
		if (*buf_lgt == (BUF_ECHO - 1))
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
	wchar_t *buf;
	int j;
	int	buf_lgt;
	int	b;

	buf = (wchar_t *)ft_memalloc(sizeof(wchar_t) * BUF_ECHO);
	tab = ft_strsplit(cmd, ' ');
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
			if (buf_lgt == (BUF_ECHO - 1))
				ft_putbuf(&buf, &buf_lgt);
			buf[buf_lgt] = L' ';
			buf_lgt++;
		}
	}
	if (buf_lgt > 0)
		ft_putbuf(&buf, &buf_lgt);
	ft_putchar('\n'); // recuperer ret -1 de ft see word
	free(buf);
	ft_free_tab(tab);
}

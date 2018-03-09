/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:06:19 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/09 15:42:10 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#define BUF_ECHO 6

static void	ft_putbuf(wchar_t **buf, int *buf_lgt)
{
	ft_putwstr(*buf);
	*buf_lgt = 0;
	ft_bwzero(*buf, BUF_ECHO);
}

static void	ft_b_quote(int *b)
{
	if (*b == 0)
		*b = 1;
	else if (*b == 1)
		*b = 0;
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
			ft_b_quote(b);
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

static void	ft_echo_next_arg(char *arg, wchar_t *buf, int *buf_lgt)
{
	if (arg != NULL)
	{
		if (*buf_lgt == (BUF_ECHO - 1))
			ft_putbuf(&buf, buf_lgt);
		buf[*buf_lgt] = L' ';
		(*buf_lgt)++;
	}
}

void		ft_echo(char **tab)
{
	wchar_t *buf;
	int		j;
	int		buf_lgt;
	int		b;

	buf = (wchar_t *)ft_memalloc(sizeof(wchar_t) * BUF_ECHO);
	buf_lgt = 0;
	j = 0;
	b = 0;
	while (tab[j] != NULL)
	{
		if (ft_see_word(tab[j], &buf, &buf_lgt, &b) == -1)
			break ;
		j++;
		ft_echo_next_arg(tab[j], buf, &buf_lgt);
	}
	if (buf_lgt > 0)
		ft_putbuf(&buf, &buf_lgt);
	ft_putchar('\n');
	free(buf);
}

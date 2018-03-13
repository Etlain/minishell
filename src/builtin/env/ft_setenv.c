/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 20:08:48 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/13 14:09:39 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// probleme env meme nom de variable et guillemet

static char	*del_quotes(char **str)
{
	char	*word;
	char	*tmp;
	int		ret;

	ret = 0;
	tmp = ft_str_delchar(*str, '"');
	if (tmp)
	{
		free(*str);
		ret = 1;
		*str = tmp;
	}
	tmp = ft_str_delchar(*str, '\'');
	if (tmp)
	{
		free(*str);
		ret = 1;
	}
	if (ret == 1)
		return (tmp);
	return (*str);
}

static char	*ft_join_env(char **tab)
{
	char	*str_left;
	char	*str;

	if (!tab || !tab[0])
		return (NULL);
	str_left = ft_strjoin(tab[0], "=");
	if (tab[1] != NULL)
	{
		str = ft_strjoin(str_left, tab[1]);
		free(str_left);
		return (str);
	}
	return (str_left);
}

static void	ft_create_var(t_sh **sh, char **tab, int print)
{
	t_list	*elem;
	char	*str;

	str = ft_join_env(tab);
	elem = ft_get_lst_elem(&(*sh)->envp->built, tab[0]);
	if (elem)
	{
		free(elem->content);
		elem->content = (void *)str;
		elem->content_size = ft_strlen(str);
	}
	else
	{
		elem = ft_lstnew((void *)str, ft_strlen(str));
		if ((*sh)->envp->built)
			ft_lstaddend(&(*sh)->envp->built, elem);
		else
			(*sh)->envp->built = elem;
		free(str);
	}
	if (print)
		ft_lst_putendl((*sh)->envp->built);
}

void		ft_setenv(t_sh **sh, char **tab, int print)
{
	int		i;
	char	*tmp;

	if (!sh || !tab)
		return ;
	i = ft_tablen(tab);
	if (i > 2)
		ft_putendl_fd("setenv : too much argument", 2);
	else if (i < 2)
		ft_lst_putendl((*sh)->envp->built);
	else
	{
		tab[0] = del_quotes(&tab[0]);
		tab[1] = del_quotes(&tab[1]);
		ft_create_var(sh, tab, print);
	}
}

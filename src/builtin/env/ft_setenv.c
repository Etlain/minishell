/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 20:08:48 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/05 17:20:38 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*ft_join_env(char **tab)
{
	char	*tmp;
	char	*str;

	tmp = ft_strjoin(tab[0], "=");
	if (tab[1] != NULL)
	{
		str = ft_strjoin(tmp, tab[1]);
		free(tmp);
		return (str);
	}
	return (tmp);
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
		ft_lstaddend(&(*sh)->envp->built, elem);
		free(str);
	}
	if (print)
		ft_lst_putendl((*sh)->envp->built);
}

void		ft_setenv(t_sh **sh, char **tab, int print)
{
	int		i;

	if (!sh || !tab)
		return ;
	i = ft_tablen(tab);
	if (i > 2)
		ft_putendl_fd("setenv : too much argument", 2);
	else if (i < 2)
		ft_lst_putendl((*sh)->envp->built);
	else
		ft_create_var(sh, tab, print);
}

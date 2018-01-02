/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:51:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/02 21:28:41 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	*ft_join_env(char **tab)
{
	char 	*tmp;
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

void	ft_setenv(t_sh **sh, char **tab)
{
	t_list	*elem;
	char	*str;
	int		i;

	i = ft_tablen(tab);
	if (i > 2)
		ft_putendl_fd("setenv : too much argument", 2);
	else if (i < 2)
		ft_lst_putendl(*(*sh)->envp->built);
	else
	{
		str = ft_join_env(tab);
		elem = ft_lstnew((void *)str, ft_strlen(str));
		//ft_lstadd((*sh)->envp->built, elem);
		ft_lstaddend((*sh)->envp->built, elem);
		ft_putendl("setenv");
		//ft_lst_putendl((*sh)->envp->built);
	}
}

int		ft_env(t_sh **sh, char *cmd)
{
	char **tab;

	tab = ft_strsplit(cmd, ' ');
	if (ft_strcmp(tab[0], "setenv") == 0)
	{
		ft_setenv(sh, &tab[1]);
		return (1);
	}
	else if (ft_strcmp(tab[0], "env") == 0)
	{
		ft_lst_putendl(*(*sh)->envp->built);
		return (1);
	}
	//ft_putendl(cmd);
	// recuperer parametre
	// -i env vide
	// -u name effacer var
	// pas de param
	//ft_lst_putendl((*sh)->envp->built);
	//gestion erreur
	return (0);
}

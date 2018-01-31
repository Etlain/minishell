/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:51:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/31 17:49:20 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int		ft_env_exec(t_sh **sh, char **tab, char *cmd)
{
	char **tmp;
	char *str;

	//str = ft_strtrim(cmd);
	if (ft_strcmp(tab[0], "-i") == 0)
	{
		ft_putendl("welcome in -i");
		/*if (tab[1])
			ft_bin(sh, tab[1]);*/
	}
	else if (ft_strcmp(tab[0], "-u") == 0)
		ft_unsetenv(sh, &tab[1]);	
	else if (ft_strchr(tab[0], '='))
	{
		tmp = ft_strsplit(tab[0], '=');
		ft_setenv(sh, tmp);
		free(tmp);
	}
	else
		return (0);
	return (1);
}

int		ft_env(t_sh **sh, char *cmd)
{
	char **tab;

	tab = ft_strsplit(cmd, ' ');
	if (ft_strcmp(tab[0], "setenv") == 0)
	{
		ft_setenv(sh, &tab[1]);
		// modify == 1
		return (1);
	}
	if (ft_strcmp(tab[0], "unsetenv") == 0)
	{
		ft_unsetenv(sh, &tab[1]);
		// modify == 1
		return (1);
	}
	else if (ft_strcmp(tab[0], "env") == 0)
	{
		if (tab[1] != NULL)
			ft_env_exec(sh, &tab[1], &cmd[3]);
		else
			ft_lst_putendl((*sh)->envp->built);
		return (1);
	}
	//gestion erreur
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:51:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/02/01 19:36:40 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char 	*ft_get_bin_param(char *cmd)
{
	char *str;
	char *tmp;

	tmp = ft_strtrim(cmd);
	str = ft_strtrim(&tmp[2]);
	free(tmp);
	return (str);
}


static void		ft_env_exec(t_sh **sh, char **tab, char *cmd)
{
	char **tmp;
	char *str;

	if (ft_strcmp(tab[0], "-i") == 0)
	{
		if (tab[1])
		{
			str = ft_get_bin_param(cmd);
			ft_bin(sh, str);
			free(str);
		}
	}
	else if (ft_strcmp(tab[0], "-u") == 0)
	{
		ft_unsetenv(sh, &tab[1]);
		(*sh)->envp->modif = 1;
	}
	else if (ft_strchr(tab[0], '='))
	{
		tmp = ft_strsplit(tab[0], '='); // corrige le probleme du =
		ft_setenv(sh, tmp);
		ft_free_tab(tmp);
		(*sh)->envp->modif = 1;
	}
}

int		ft_env(t_sh **sh, char *cmd)
{
	char **tab;

	tab = ft_strsplit(cmd, ' ');
	if (ft_strcmp(tab[0], "setenv") == 0)
	{
		ft_setenv(sh, &tab[1]);
		(*sh)->envp->modif = 1;
		return (1);
	}
	if (ft_strcmp(tab[0], "unsetenv") == 0)
	{
		// probleme si plusieurs egale a cause du strsplit
		ft_unsetenv(sh, &tab[1]);
		(*sh)->envp->modif = 1;
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
	ft_free_tab(tab);
	//gestion erreur
	return (0);
}

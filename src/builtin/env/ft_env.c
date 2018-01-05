/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:51:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/05 20:42:43 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
		ft_lst_putendl((*sh)->envp->built);
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

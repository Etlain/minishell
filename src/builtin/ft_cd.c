/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:18:28 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/05 17:24:45 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// verifier cd pour ln

static void	ft_modif_env(t_sh **sh, char *cmd, char *var)
{
	char	*str;

	str = ft_strjoin(cmd, var);
	ft_env(sh, str, 0);
	free(str);
}

static void	ft_cd_exec(t_sh **sh, char *path, int b)
{
	char	buf[256];
	char	*str;
	char	*tmp;

	ft_bzero(&buf, 256);
	if (chdir(path) < 0) // modifier pwd
		ft_putendl_fd("cd : chdir error", 2);
	if (getcwd(buf, 256) != NULL)
	{
		if (b)
			ft_putendl(buf);
		tmp = ft_get_one_env((*sh)->envp->built, "PWD");
		ft_modif_env(sh, "setenv OLDPWD ", tmp);
		ft_modif_env(sh, "setenv PWD ", buf);
	}
	else
		ft_putendl_fd("cd : getcwd error", 2);
}

void		ft_cd(t_sh **sh, char *cmd)
{
	char 	**tab;
	char	*path;
	int		lgt_tab;
	int		b;

	b = 0;
	tab = ft_strsplit(cmd, ' ');
	lgt_tab = ft_tablen(tab);
	// cd home si pas param
	if (lgt_tab > 1)
	{
		ft_putendl_fd("cd : too much param", 2);
		return ;
	}
	if (ft_strcmp(tab[0], "-") == 0)
	{
		b = 1;
		path = ft_get_one_env((*sh)->envp->built, "OLDPWD");
	}
	else
		path = tab[0];
	ft_cd_exec(sh, path, b);
	ft_free_tab(tab);
}

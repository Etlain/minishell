/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:51:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/08 17:10:48 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char		*ft_get_bin_param(char *cmd)
{
	char	*str;
	char	*tmp;

	tmp = ft_strtrim(cmd);
	str = ft_strtrim(&tmp[2]);
	free(tmp);
	return (str);
}

static char		**ft_get_param_equal(char *str)
{
	char	**tab;
	int		i;
	int		lgt;

	lgt = ft_strlen(str);
	if (str == NULL || lgt < 2 || str[0] == '=')
		return (NULL);
	i = 0;
	while (i < lgt && str[i] != '=')
		i++;
	if (str[i] == '=')
	{
		tab = (char **)ft_memalloc(sizeof(char *) * 3);
		tab[0] = ft_strnew(i);
		ft_strncpy(tab[0], str, i);
		tab[1] = ft_strnew(lgt - i);
		ft_strncpy(tab[1], &str[i + 1], lgt);
		tab[2] = NULL;
	}
	else
		tab = NULL;
	return (tab);
}

static void		ft_unsetenv_exec(t_sh **sh, char **tab)
{
	ft_unsetenv(sh, &tab[1]);
	(*sh)->envp->modif = 1;
}

static void		ft_env_exec(t_sh **sh, char **tab, char *cmd, int print)
{
	char	**tmp;
	char	*str;

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
		ft_unsetenv_exec(sh, tab);
	else if (ft_strchr(tab[0], '='))
	{
		if (!(tmp = ft_get_param_equal(tab[0])))
			return ;
		ft_setenv(sh, tmp, print);
		ft_free_tab(tmp);
		(*sh)->envp->modif = 1;
	}
}

int				ft_env(t_sh **sh, char *cmd, int print)
{
	char	**tab;

	tab = ft_strsplit(cmd, ' ');
	if (tab && tab[0] && tab[1] && ft_strcmp(tab[0], "setenv") == 0)
	{
		ft_setenv(sh, &tab[1], print);
		(*sh)->envp->modif = 1;
	}
	else if (tab && tab[0] && ft_strcmp(tab[0], "unsetenv") == 0)
		ft_unsetenv_exec(sh, tab);
	else if (tab && tab[0] && ft_strcmp(tab[0], "env") == 0)
	{
		if (tab[1] != NULL)
			ft_env_exec(sh, &tab[1], &cmd[3], print);
		else
			ft_lst_putendl((*sh)->envp->built);
	}
	else
	{
		ft_free_tab(tab);
		return (0);
	}
	ft_free_tab(tab);
	return (1);
}

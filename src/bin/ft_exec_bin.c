/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:51:26 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/05 16:30:57 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_execve_bin(t_sh **sh, char **tab_cmd, char *folder, char *cmd)
{
	char	*path;
	int		ret;

	ret = 0;
	if (ft_strncmp(cmd, tab_cmd[0], ft_strlen(tab_cmd[0])) == 0)
	{
		if (folder)
		{
			path = ft_strjoin_path(folder, tab_cmd[0]);
			ret = execve(path, &tab_cmd[0], (*sh)->envp->bin);
		}
		else
			ret = execve(tab_cmd[0], &tab_cmd[0], (*sh)->envp->bin);
		if (ret < 0)
			ft_error_cmd(cmd);
	}
}

int			ft_exec_bin(t_sh **sh, char *path_folder, char *cmd)
{
	char	**tab_cmd;
	char	*path;
	int		ret;

	if ((*sh)->envp->modif)
	{
		ft_free_tab((*sh)->envp->bin);
		(*sh)->envp->bin = ft_lst_to_tab((*sh)->envp->built);
		(*sh)->envp->modif = 0;
	}
	tab_cmd = ft_strsplit(cmd, ' ');
	(*sh)->process = fork();
	if ((*sh)->process == 0)
	{
		ft_execve_bin(sh, tab_cmd, path_folder, cmd);
		ft_free_tab(tab_cmd);
		exit(0);
	}
	else
		waitpid((*sh)->process, NULL, 0);
	ft_free_tab(tab_cmd);
	return (1);
}

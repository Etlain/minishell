/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:51:26 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/31 16:58:22 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec_bin(t_sh **sh, char *path_folder, char *cmd)
{
	char	**tab_cmd;
	char	*path;
	int		ret;

	tab_cmd = ft_strsplit(cmd, ' ');
	(*sh)->process = fork();
	if ((*sh)->process == 0)
	{
		if (ft_strncmp(cmd, tab_cmd[0], ft_strlen(tab_cmd[0])) == 0)
		{
			// condition pour modifier envp->bin grace a modif
			if (path_folder)
			{
				path = ft_strjoin_path(path_folder, tab_cmd[0]);
				ret = execve(path, &tab_cmd[0], (*sh)->envp->bin);
			}
			else
				ret = execve(tab_cmd[0], &tab_cmd[0], (*sh)->envp->bin);
			// sh : exec format error : ./t
			if (ret < 0)
				ft_error_cmd(cmd);
		}
		ft_free_tab(tab_cmd);
		exit(0);
	}
	else
		waitpid((*sh)->process, NULL, 0);
	ft_free_tab(tab_cmd);
	return (1);
}

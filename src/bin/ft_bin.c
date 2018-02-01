/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:06:13 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/02/01 18:24:14 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		**ft_fill_bin_path(t_list *built)
{
	char **bin_path;

	bin_path = ft_strsplit(ft_get_one_env(built, "PATH"), ':');
	//ft_putendl_tab(bin_path);
	return (bin_path);
}

static int	ft_is_folder_cmd(char *folder, char *cmd)
{
	struct dirent 	*file;
	void			*dir;

	if (folder == NULL)
		return (0);
	dir = opendir(folder);
	while ((file = readdir(dir)) != NULL)
	{
		if (ft_strncmp(cmd, file->d_name, ft_strlen(file->d_name)) == 0)
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

static char	*ft_get_folder_bin(char **tab_folder, char *cmd)
{
	int i;

	i = 0;
	while (tab_folder[i] != NULL)
	{
		if (ft_is_folder_cmd(tab_folder[i], cmd))
			return (tab_folder[i]);
		i++;
	}
	return (NULL);
}

int	ft_bin(t_sh **sh, char *cmd)
{
	char *path_folder;
	int	ret;

	ret = 0;
	path_folder = NULL;
	path_folder = ft_get_folder_bin((*sh)->envp->bin_path, cmd);
	if (path_folder == NULL)
		return (0);
	else
		ret = ft_exec_bin(sh, path_folder, cmd);
	//free(path_folder); ne pas utiliser ce free
	// free
	return (ret);
}

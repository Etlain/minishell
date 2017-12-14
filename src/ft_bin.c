/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:06:13 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/14 16:26:52 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**ft_fill_bin_path(char **envp)
{
	char **bin_path;

	bin_path = ft_strsplit(ft_get_one_env(envp, "PATH"), ':');
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
			return (1);
	}
	closedir(dir);
	return (0);
}

// static function qui verifie dans chaque repertoire

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
	char **tab_cmd;
	char *path_folder;
	char *path;

	path_folder = ft_get_folder_bin((*sh)->bin_path, cmd);
	if (path_folder == NULL)
		return (0);
	else
	{
		tab_cmd = ft_strsplit(cmd, ' ');
		if (ft_strncmp(cmd, tab_cmd[0], ft_strlen(tab_cmd[0])) == 0)
		{
			ft_putendl("hello");
			(*sh)->process = fork();
			if ((*sh)->process == 0)
			{
				path = ft_strjoin_path(path_folder, tab_cmd[0]);
				execve(path, &tab_cmd[0], (*sh)->envp);
				free(path);
				ft_free_tab(tab_cmd);
				return (0);
			}
			else
			{
				waitpid((*sh)->process, NULL, 0);
				(*sh)->process = 1;
			}
			ft_free_tab(tab_cmd);
			return (1);
		}
		ft_free_tab(tab_cmd);
	}
	free(path_folder);
	// free
	return (0);
}

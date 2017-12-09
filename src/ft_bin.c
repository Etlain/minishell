/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:06:13 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/09 12:56:02 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

int	ft_bin(t_sh **sh, char *cmd)
{
	char **tab_cmd;

	
	ft_printf("tets int ret : %d\n", ft_is_folder_cmd("/bin", cmd));
	//tab_cmd = ft_strsplit(cmd, ' ');
	/*if (ft_strncmp(cmd, "ls", 4) == 0)
	{
		(*sh)->process = fork();
		if ((*sh)->process == 0)
			execve("/bin/ls", &tab_cmd[0], (*sh)->envp);
		else
			waitpid((*sh)->process, NULL, 0);
		return (1);
	}*/
	// free
	return (0);
}

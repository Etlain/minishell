/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 22:42:17 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/13 19:06:26 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char **ft_init_cmd(char *input)
{
	char **cmd;
	char *tmp;
	int     i;

	cmd = ft_strsplit(input, ';');
	free(input);
	i = 0;
	while (cmd[i] != NULL)
	{
		tmp = cmd[i];
		cmd[i] = ft_strtrim(tmp);
		free(tmp);
		i++;
	}
	return (cmd);
}

void    ft_init_sh(t_sh **sh, char **envp)
{
	*sh = (t_sh *)malloc(sizeof(t_sh));
	(*sh)->process = 1;
	(*sh)->cmd = NULL;
	(*sh)->envp = envp; // envp du main, malloc pas necessaire
	(*sh)->builtin = ft_tab_builtin();
	(*sh)->bin_path = ft_fill_bin_path(envp);
}

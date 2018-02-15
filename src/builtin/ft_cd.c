/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:18:28 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/02/15 21:54:40 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// verifier cd pour ln

void ft_cd(t_sh **sh, char *cmd)
{
	char 	str;
	int		lgt_tab;
	int 	b;
	char 	*path;
	char 	buf[256];

	b = 0;
	str = ft_strtrim(cmd, ' ');
	lgt_tab = ft_tablen(tab);
	if (lgt_tab > 1)
	{
		ft_putendl_fd("cd : too much param", 2);
		return ();
	}
	/*if (ft_strcmp(tab[0], "-") == 0)
	{
		b = 1;
		path = oldpath;
	}
	*/
	ft_bzero(&buf, 256);
	if (chdir(path) < 0) // modifier pwd
		ft_putendl_fd("cd : chdir error", 2);
	if (getcwd(buf, 256) == NULL)
		ft_putendl_fd("cd : getcwd error", 2);
	// env modifier path
	ft_putendl(buf);
	free(path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:43:46 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/02/07 18:43:41 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_builtin(t_sh **sh, char *cmd)
{
	int b;
 
	b = 0;
	if (ft_strncmp(cmd, "exit", 4) == 0)
		return (-1);
	else if (ft_strncmp(cmd, "echo", 4) == 0)
	{
		ft_echo(&cmd[4]);
		return (1);
	}
	else if (ft_strncmp(cmd, "cd", 2) == 0)
	{
		ft_cd(sh, &cmd[2]);
		return (1);
	}
	else
		b = ft_env(sh, cmd);
	return (b);
}

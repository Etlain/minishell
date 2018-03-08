/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:43:46 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/08 17:48:37 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_builtin(t_sh **sh, char *cmd)
{
	int	b;

	b = 0;
	if (ft_strcmp(cmd, "exit") == 0)
		return (-1);
	else if (ft_strcmp(cmd, "echo") == 0)
	{
		ft_echo(&cmd[4]);
		return (1);
	}
	else if (ft_strcmp(cmd, "cd") == 0)
	{
		ft_cd(sh, &cmd[2]);
		return (1);
	}
	else
		b = ft_env(sh, cmd, 1);
	return (b);
}

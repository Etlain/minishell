/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:57:29 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/14 17:10:22 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error_cmd(char *cmd)
{
	char **tab;
	char *str;

	tab = ft_strsplit(cmd, ' ');
	str = ft_strjoin("sh : command not found : ", tab[0]);
	ft_putendl_fd(str, 2);
	free(str);
	ft_free_tab(tab);
}

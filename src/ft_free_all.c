/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:33:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/05 12:58:40 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_free_lst(void *elem, size_t size)
{
	free(elem);
}

void		ft_free_sh(t_sh **sh)
{
	ft_free_tab((*sh)->envp->bin_path);
	ft_free_tab((*sh)->envp->bin);
	ft_lstdel(&(*sh)->envp->built, ft_free_lst);
	free((*sh)->envp);
	ft_free_tab((*sh)->cmd);
	free(*sh);
}

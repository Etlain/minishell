/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 20:11:57 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/01/05 21:59:02 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_unsetenv(t_sh **sh, char **tab)
{
	t_list	*tmp;
	char	*str;
	int		i;

	i = ft_tablen(tab);
	if (i < 1)
		ft_putendl_fd("setenv : too few argument", 2);
	else
	{
		i = 0;
		while (tab[i] != NULL)
		{
			tmp = ft_get_lst_elem(&(*sh)->envp->built, tab[i]);
			if (tmp != NULL)
				ft_lstdel_elem(&tmp);
			i++;
		}
	}
}

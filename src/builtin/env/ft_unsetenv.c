/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 20:11:57 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/03/08 09:37:43 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_unsetenv(t_sh **sh, char **tab)
{
	t_list	*tmp;
	t_list	*last;
	int		i;

	i = ft_tablen(tab);
	if (i < 1)
		ft_putendl_fd("unsetenv : too few argument", 2);
	else
	{
		i = 0;
		while (tab[i] != NULL)
		{
			tmp = ft_get_lst_elem_prev(&(*sh)->envp->built, tab[i], &last);
			if (tmp != NULL)
			{
				if (last != NULL)
					ft_lstdel_elem(&tmp, &last);
				else if (tmp != NULL)
					ft_lstdel_elem(&tmp, NULL);
			}
			i++;
		}
	}
}

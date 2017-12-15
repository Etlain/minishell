/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:51:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/15 22:28:03 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_env(t_sh **sh)
{
	// recuperer parametre
	// -i env vide
	// -u name effacer var
	// pas de param
	ft_lst_putendl((*sh)->envp->built);
	//gestion erreur
}

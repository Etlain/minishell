/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:50:27 by mmouhssi          #+#    #+#             */
/*   Updated: 2018/02/19 17:13:11 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_prompt(t_list *built)
{
	char *tmp;
	char *prompt;

	tmp = ft_get_one_env(built, "USER");
	if (tmp != NULL)
		prompt = ft_strjoin(tmp, "$> ");
	else
		prompt = ft_strjoin("sh", "$>");
	return (prompt);
}

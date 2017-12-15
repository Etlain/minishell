/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:50:27 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/15 14:25:59 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_prompt(t_list *built)
{
	char *tmp;
	char *prompt;

	tmp = ft_get_one_env(built, "USER"); // PWD
	prompt = ft_strjoin(tmp, "$> ");
	return (prompt);
}

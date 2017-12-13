/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:17:06 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/13 17:32:36 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lib/libft/includes/libft.h"
# include <dirent.h>

typedef struct	s_sh
{
	int			process;
	char 		**envp;
	char 		**cmd;
	void		***builtin;
	char		**bin_path;
}				t_sh;

char			**ft_init_cmd(char *input);
void			ft_init_sh(t_sh **sh, char **envp);
void			ft_env(t_sh **sh);
char			*ft_get_one_env(char **envp, char *name);
char			*ft_prompt(char **envp);
void			***ft_tab_builtin();
int				ft_builtin(t_sh **sh, char *cmd);
int				ft_bin(t_sh **sh, char *cmd);
char			**ft_fill_bin_path(char **envp);

#endif

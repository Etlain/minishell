/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:17:06 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/12/15 16:19:05 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lib/libft/includes/libft.h"
# include <dirent.h>

typedef struct	s_envp
{
	t_list		*built;
	char		**bin;
	char		**bin_path;
	int			modif;
}				t_envp;



typedef struct	s_sh
{
	int			process;
	t_envp 		*envp;
	char 		**cmd;
	void		***builtin;
}				t_sh;

char			**ft_init_cmd(char *input);
void			ft_init_sh(t_sh **sh, char **envp);
void			ft_env(t_sh **sh);
char			*ft_get_one_env(t_list *built, char *name);
char			*ft_prompt(t_list *built);
void			***ft_tab_builtin();
int				ft_builtin(t_sh **sh, char *cmd);
int				ft_bin(t_sh **sh, char *cmd);
char			**ft_fill_bin_path(t_list *built);
void			ft_error_cmd(char *cmd);
t_list			*ft_lst_cpy_envp(char **envp);
void			ft_lst_putendl(t_list *lst);
int				ft_exec_bin(t_sh **sh, char *path_folder, char *cmd);

#endif

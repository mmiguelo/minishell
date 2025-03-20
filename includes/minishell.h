/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:11:42 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/20 10:41:32 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

typedef struct s_bt
{
	char		***envp;
	char		**cmd;
	char		***export;
}				t_bt;

//function pointer type for builtins
typedef int	(*t_builtin)(char **, t_bt *);

/*=============================================================================#
#                               BUILTIN                                        #
#=============================================================================*/

t_builtin	ft_isbuiltin(char *cmd, t_bt *shell);
int			ft_echo(char **args, t_bt *shell);
int			ft_cd(char **args, t_bt *shell);
int			ft_pwd(char **args, t_bt *shell);
int			ft_export(char **args, t_bt *shell);
int			ft_unset(char **args, t_bt *shell);
int			ft_env(char **args, t_bt *shell);
int			get_env_line(char *var, t_bt *shell);
void		ft_erase_var(char *var, t_bt *shell);
int			validate_var(char *var);
void		ft_init(t_bt *shell, char **envp);
void		init_env(t_bt *shell, char **envp);
void		when_no_env(t_bt *shell);
int			ft_exit(char **args, t_bt *shell);

/*=============================================================================#
#                               UTILS                                          #
#=============================================================================*/

void		ft_init(t_bt *shell, char **envp);
void		ft_signals(void);
void		ft_minishell(t_bt *shell, char **envp);
void		sigint_handler(int sig);

/*=============================================================================#
#                      	         FREE                                          #
#=============================================================================*/

void		free_envp(t_bt *shell, int i);
int			print_msg_error(char *error);

#endif
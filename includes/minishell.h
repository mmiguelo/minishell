/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:11:42 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/22 16:29:00 by mmiguelo         ###   ########.fr       */
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
	char		**envp;
	char		**cmd;
}				t_bt;

//function pointer type for builtins
typedef int	(*t_builtin)(char **, t_bt *);

/*=============================================================================#
#                               BUILTIN                                        #
#=============================================================================*/

t_builtin	ft_isbuiltin(char *cmd, t_bt *shell);
//echo
int			ft_echo(char **args, t_bt *shell);
int			ft_cd(char **args, t_bt *shell);
int			ft_pwd(char **args, t_bt *shell);
int			ft_unset(char **args, t_bt *shell);
int			ft_exit(char **args, t_bt *shell);
int			ft_env(char **args, t_bt *shell);
int			get_env_line(char *var, t_bt *shell);
int			export_error(char *arg);
int			check_if_var_is_in_env(char *arg, t_bt shell);
int			validate_var(char *var);
int			ft_export(char **args, t_bt *shell);
int			check_for_value(char *arg);
int			check_export_var(char **args, t_bt *shell);
char		*get_export_var(char *arg);
char		*get_export_value(char *arg);
char		**init_env(char **envp);
void		sort_export(char **new_export);
void		when_no_env(t_bt *shell);
void		ft_erase_var(char *var, t_bt *shell);
void		handle_export_var(char *arg, t_bt *shell);
void		print_invalid_var(char *var);

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:18:53 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/17 17:53:58 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_line(char *var, t_shell *shell)
{
	int	i;
	int len;

	len = ft_strlen(var);
	if (!validate_var(var))
		return (-1);
	i = -1;
	if (!shell->envp)
		return (-1);
	while (shell->envp[++i])
	{
		if (ft_strncmp(shell->envp[i], var, len) == 0 && (*(shell->envp[i])
			 + len == '\0' || *(shell->envp[i]) + len == '='))
			return (i);
	}
	return (-1);
}

int	validate_var(char *var)
{
	int	i;
	
	i = 0;
	if(var[i] != '_' && !ft_isalpha(var[i]))
		return (0);
	while(++i)
	{
		if(var[i] != '_' && !ft_isalnum(var[i]))
			return(0);
	}
	return (i);
}

t_builtin	ft_isbuiltin(char *cmd, t_shell *shell)
{
	(void)shell;
	static char	*builtins[8] = {
		"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	static int	(*builtin_ft[8])(char **, t_shell *) = {
		&ft_echo, &ft_cd, &ft_pwd, &ft_export, &ft_unset, &ft_env, &ft_exit};
	int			i;

	i = -1;
	if (!cmd)
		return (NULL);
	while (builtins[++i])
	{
		if (strncmp(builtins[i], cmd, ft_strlen(builtins[i]) + 1) == 0)
			return (builtin_ft[i]);
	}
	return (NULL);
}

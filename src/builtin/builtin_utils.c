/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:18:53 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/19 08:48:02 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_line(char *var, t_shell *shell)
{
	int		i;
	int		len;
	char	**env;

	len = ft_strlen(var);
	if (!validate_var(var))
		return (-1);
	i = -1;
	if (!shell->envp)
		return (-1);
	env = *(shell->envp);
	while (env[++i])
	{
		if (ft_strncmp(env[i], var, len) == 0
			&& (env[i][len] == '\0' || env[i][len] == '='))
			return (i);
	}
	return (-1);
}

t_builtin	ft_isbuiltin(char *cmd, t_shell *shell)
{
	static char	*builtins[8] = {
		"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	static int	(*builtin_ft[8])(char **, t_shell *) = {
		&ft_echo, &ft_cd, &ft_pwd, &ft_export, &ft_unset, &ft_env, &ft_exit};
	int			i;

	(void)shell;
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

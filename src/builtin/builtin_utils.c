/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:18:53 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 14:51:00 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Searches for an environment variable in the shell's list.
 * 
 * This function scans the shell's environment (`shell->envp`) for a variable
 * that matches `var`. It returns the index of the variable if found, or -1
 * if the variable is not found or invalid.
 * 
 * @param var  The name of the environment variable to search for.
 * @param shell The shell structure containing the environment (`shell->envp`).
 * @return int The index of the variable in `shell->envp` if found.
 * 		   -1 if the variable is not found or invalid.
 */
int	get_env_line(const char *var, t_bt *shell)
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
	env = shell->envp;
	while (env[++i])
	{
		if (ft_strncmp(env[i], var, len) == 0
			&& (env[i][len] == '\0' || env[i][len] == '='))
			return (i);
	}
	return (-1);
}

/**
 * @brief Checks if a command is a built-in function and returns its
 * corresponding function pointer.
 * 
 * This function compares the given command (`cmd`) with a predefined
 * list of shell built-in commands.
 * If a match is found, it returns a pointer to the corresponding built-in
 * function.
 * Otherwise, it returns `NULL`, indicating that the command is not a built-in.
 * 
 * @param cmd The command string to check.
 * @param shell A pointer to the shell structure (unused in this function).
 * @return t_builtin A function pointer to the matching built-in command.
 * 		   `NULL` if the command is not a built-in.
 */
t_builtin	ft_isbuiltin(char *cmd, t_bt *shell)
{
	static char	*builtins[8] = {
		"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};
	static int	(*builtin_ft[8])(char **, t_bt *) = {
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

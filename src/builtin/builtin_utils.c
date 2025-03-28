/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:18:53 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/28 11:23:06 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

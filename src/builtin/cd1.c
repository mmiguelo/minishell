/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:19:57 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/04/01 16:09:12 by mmiguelo         ###   ########.fr       */
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

char	*get_env_value(const char *var, t_bt *shell)
{
	int	i;

	i = get_env_line(var, shell);
	if (i == -1)
		return (NULL);
	return (shell->envp[i] + ft_strlen(var) + 1);
}

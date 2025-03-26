/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:19:37 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 13:06:35 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 
 * 
 * @param shell 
 * @param var 
 * @param path 
 */
void	update_env(t_bt *shell, const char *var, char *path)
{
	int		i;
	char	*new_line;
	char	**env;

	i = get_env_line(var, shell);
	if (i == -1)
	{
		env = shell->envp;
		while (*env)
			env++;
		new_line = ft_strjoin(var, "=");
		new_line = ft_strjoin(new_line, path);
		*env = new_line;
	}
	else
	{
		free(shell->envp[i]);
		shell->envp[i] = ft_strjoin(var, "=");
		shell->envp[i] = ft_strjoin(shell->envp[i], path);
	}
}

int	ft_cd(char **args, t_bt *shell)
{
	char	cwd[1024];
	char	*new_cwd;
	
	if (!shell->envp)
		return (1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (perror("minishell: cd"), 1);
	if (args[1] && (args[1][0] == '-') && args[1][1])
		return(ft_printf("minishell: cd: %s: invalid option\n", args[1]), 2);
	if (args[2])
		ft_printf("minishell: cd: too many arguments\n");
	if (!args[1])
	{
		new_cwd = getenv("HOME");
		if (!new_cwd)
			return (perror("minishell: cd: HOME not set"), 1);
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		new_cwd = getenv("OLDPWD");
		if (!new_cwd)
			return (perror("minishell: cd: OLDPWD not set"), 1);
		ft_printf("%s\n", new_cwd);
	}
	else
		new_cwd = args[1];
	if (chdir(new_cwd) == -1)
		return (ft_printf("minishell: cd: %s: %s\n", new_cwd, strerror(errno)), 1);
	update_env(shell, "OLDPWD", cwd);
	update_env(shell, "PWD", new_cwd);
	return (0);
}

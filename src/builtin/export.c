/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:37 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/04/04 18:16:37 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	concatenate_value(char **var, char *new_var, t_bt *shell, int i)
{
	char	*new_value;
	char	*old_value;

	old_value = get_value(shell->envp[i]);
	new_value = ft_strdup(ft_strnstr(*var, "+=", ft_strlen(*var)) + 2);
	//free(*var);
	*var = ft_strdup_free(ft_strjoin(new_var, "="),
			ft_strdup_free(old_value, new_value));
	free(shell->envp[i]);
	shell->envp[i] = *var;
}

void	append_var_to_envp(char **arg, t_bt *shell)
{
	int		i;
	char	*new_var;
	char	*new_value;

	new_var = get_export_var(*arg);
	i = get_env_line(new_var, shell);
	if (i >= 0)
	{
		if (ft_strchr(shell->envp[i], '='))
			return (concatenate_value(arg, new_var, shell, i));
		else
			return (give_value(arg, new_var, shell, i));
	}
	new_value = ft_strdup(ft_strnstr(*arg, "+=", ft_strlen(*arg)) + 1);
	*arg = ft_strjoin(new_var, new_value);
	add_var_to_envp(*arg, shell);
	free(new_value);
	free(new_var);
}

void	handle_export_var(char **arg, t_bt *shell, char *var, char *value)
{
	if (ft_strnstr(*arg, "+=", ft_strlen(*arg)))
		append_var_to_envp(&(*arg), shell);
	else if (ft_strchr(*arg, '='))
	{
		ft_erase_var(var, shell);
		add_var_to_envp(*arg, shell);
	}
	else if (!value)
	{
		ft_erase_var(var, shell);
		add_var_to_envp(*arg, shell);
	}
}

/**
 * @brief Prints all the environment variables with the `declare -x` prefix.
 * 
 * This function iterates over the environment variables stored in the
 * `shell->envp` array, makes a copy of each variable, sorts them, and then
 * prints them to the standard output with the format `declare -x
 * <variable>=<value>`. It mimics the output of the `export` command in Bash,
 * showing each variable with the `declare -x` prefix.
 * 
 * @param shell Pointer to the shell structure. It contains the `envp` array,
 * which holds the environment variables.
 * @return int Returns `0` upon successful completion. If an error occurs
 * during memory allocation or printing, it will return `0` (indicating
 * failure in some cases).
 */
int	ft_print_export(t_bt *shell)
{
	int		i;
	char	**new_export;
	int		j;

	i = -1;
	new_export = ft_calloc(ft_arrlen(shell->envp) + 1, sizeof(char *));
	if (!new_export)
		return (0);
	while (shell->envp[++i])
		new_export[i] = ft_strdup(shell->envp[i]);
	sort_export(new_export);
	i = -1;
	while (new_export[++i])
	{
		j = 0;
		while (new_export[i][j])
		{
			if (new_export[i][j] == '=' && new_export[i][j + 1] != '\"')
			{
				new_export[i] = add_double_quotes(new_export[i], j + 1);
				break ;
			}
			j++;
		}
		ft_printf("declare -x %s\n", new_export[i]);
		free(new_export[i]);
	}
	free(new_export);
	return (0);
}

/**
 * @brief Implements the `export` command for the shell.
 * 
 * This function handles the `export` command, which is used to set or display
 * environment variables. If no arguments are provided, it will print the
 * current environment variables. If an argument is provided, it checks if the
 * argument has a valid format and sets the environment variable accordingly.
 * 
 * @param args Array of arguments passed to the `export` command. The first
 * element (`args[0]`) is `"export"`, and subsequent elements are the variables
 * to be set in the environment.
 * @param shell Pointer to the shell structure. It contains the environment
 * variables (`envp`) and other shell-specific information.
 * @return int Returns `1` if an error occurs, such as an invalid variable
 * format, or `0` if the command is processed successfully.
 */
int	ft_export(char **args, t_bt *shell)
{
	int	i;

	i = 1;
	if (!args[i])
		return (ft_print_export(shell));
	while (args[i++])
	{
		if (args[i] && export_error(args[i]))
			return (1);
	}
	return (check_export_var(args, shell));
}

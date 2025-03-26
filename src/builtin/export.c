/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:37 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 13:54:44 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_export_var(char **arg, t_bt *shell, char *var, char *value)
{
	/* 	if (ft_strchr(*arg, '='))
			update_var(arg, shell);
		else if (!value)
			add_var_in_env(arg, shell);*/
	//TODO: check if variable already exists
	//TODO: if it exists, update it
	//TODO: if it doesn't exist, add it to the list
	//TODO: check if there is a value
	//TODO: if there is, add it to the variable
	//TODO: check if there is +=
	//TODO: if there is, append the value to the variable
	(void)arg;
	(void)shell;
	(void)var;
	(void)value;
}

int	check_export_var(char **args, t_bt *shell)
{
	int		i;
	char	*var;
	char	*value;

	(void)shell;
	i = 0;
	while (args[++i])
	{
		var = get_export_var(args[i]);
		value = get_export_value(args[i]);
		if (validate_var(var))
		{
			handle_export_var(&args[i], shell, var, value);
			ft_printf("var: %s\n", var);
			ft_printf("value: %s\n", value);
		}
		else
			print_invalid_var(var);
		free(var);
		if (value)
			free(value);
	}
	return (0);
}

void	sort_export(char **new_export)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (new_export[++i] != NULL)
	{
		j = i;
		while (new_export[++j] != NULL)
		{
			if (ft_strcmp(new_export[i], new_export[j]) > 0)
			{
				temp = new_export[i];
				new_export[i] = new_export[j];
				new_export[j] = temp;
			}
		}
	}
}

int	ft_print_export(t_bt *shell)
{
	int		i;
	char	**new_export;

	i = 0;
	new_export = ft_calloc(ft_arrlen(shell->envp) + 1, sizeof(char *));
	if (!new_export)
		return (0);
	while (shell->envp[i] != NULL)
	{
		new_export[i] = ft_strdup(shell->envp[i]);
		i++;
	}
	sort_export(new_export);
	i = 0;
	while (new_export[i] != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(new_export[i], 1);
		ft_putstr_fd("\n", 1);
		free(new_export[i]);
		i++;
	}
	free(new_export);
	return (0);
}

/**
 * @brief Implements the `export` command for the shell.
 * 
 * This function handles the `export` command, which is used to set or display environment
 * variables. If no arguments are provided, it will print the current environment variables.
 * If an argument is provided, it checks if the argument has a valid format and sets the 
 * environment variable accordingly.
 * 
 * @param args Array of arguments passed to the `export` command. The first element
 *               (`args[0]`) is `"export"`, and subsequent elements are the variables
 *               to be set in the environment.
 * @param shell Pointer to the shell structure. It contains the environment variables 
 *               (`envp`) and other shell-specific information.
 * @return int Returns `1` if an error occurs, such as an invalid variable format,
 *               or `0` if the command is processed successfully.
 */
int	ft_export(char **args, t_bt *shell)
{
	int	i;

	i = 0;
	if (!args[1])
		return (ft_print_export(shell));
	while (args[++i])
	{
		if (args[i] && export_error(args[i]))
			return (1);
	}
	return (check_export_var(args, shell));
}

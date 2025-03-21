/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:37 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/21 17:03:43 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_export_var(char *arg, t_bt *shell)
{
	//TODO: check if variable already exists
	//TODO: if it exists, update it
	//TODO: if it doesn't exist, add it to the list
	//TODO: check if there is a value
	//TODO: if there is, add it to the variable
	//TODO: check if there is +=
	//TODO: if there is, append the value to the variable
	(void)arg;
	(void)shell;
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
			handle_export_var(args[i], shell);
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
		return 0;
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

int	ft_export(char **args, t_bt *shell)
{
	int i;
	
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
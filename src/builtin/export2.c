/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:14:55 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/31 11:45:10 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Processes and validates environment variable assignments from the
 * export command.
 * 
 * This function processes each argument passed to the `export` command,
 * separating the variable names and their values. It validates the variables,
 * and if valid, it calls a handler function to perform the export action. If a
 * variable is invalid, it prints an error message. The function also prints the
 * variable and its value for debugging purposes.
 * 
 * @param args Array of strings representing the arguments passed to the `export`
 * command. Each argument can be a variable assignment of the form `VAR=VALUE`.
 * @param shell Pointer to the shell structure, which contains the environment
 * variables and other data.
 * @return int Returns `0` upon successful completion. If an error occurs (such
 * as an invalid variable), it prints an error message and returns `0`.
 */
int	check_export_var(char **args, t_bt *shell)
{
	int		i;
	char	*var;
	char	*value;

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
		if (var)
			free(var);
		if (value)
			free(value);
	}
	return (0);
}

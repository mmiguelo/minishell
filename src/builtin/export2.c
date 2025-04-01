/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:14:55 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/04/01 12:38:41 by mmiguelo         ###   ########.fr       */
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
			handle_export_var(&args[i], shell, var, value);
		else
			print_invalid_var(var);
		if (var)
			free(var);
		if (value)
			free(value);
	}
	return (0);
}

char	*add_double_quotes(char *str, int j)
{
	char	*new_str;
	int		i;
	int		k;

	new_str = ft_calloc(ft_strlen(str) + 3, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		if (i == j)
			new_str[k++] = '\"';
		new_str[k++] = str[i++];
	}
	new_str[k++] = '\"';
	new_str[k] = '\0';
	free(str);
	return (new_str);
}

/**
 * @brief Sorts an array of strings in lexicographical order.
 * 
 * This function sorts an array of strings (environment variables in this case)
 * in ascending lexicographical order using a simple bubble sort algorithm. It is
 * used to sort the environment variables before printing them in the
 * `ft_print_export` function, ensuring they are listed in alphabetical order.
 * 
 * @param new_export Array of strings (environment variables) to be sorted. Each
 * string represents an environment variable in the format `VAR=VALUE`.
 */
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

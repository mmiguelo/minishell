/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:37 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/20 15:14:06 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Checking for Arguments
If args[1] == NULL, list all exported variables.

Adding or Updating an Environment Variable
1. Parse VAR=VALUE format. check
2. Validate the variable name. check
3. Check if it already exists in envp.
4. If it exists, update it.
5. If not, add it to the list. */

/* void	handle_export_var(char *arg, t_bt *shell)
{
	
} */

int	check_export_var(char *arg)
{
	int		i;
	char	*var;
	char	*value;

	i = 0;
	var = get_export_var(arg);
	value = get_export_value(arg);
	ft_printf("var: %s\n", var);
	ft_printf("value: %s\n", value);
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
	if (!args[1])
		return (ft_print_export(shell));
	if (args[1] && export_error(args[1]))
		return (1);
	return (check_export_var(args[1]));
}

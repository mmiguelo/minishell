/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:37 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/20 10:42:17 by mmiguelo         ###   ########.fr       */
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

int	check_for_value(char *arg)
{
	int i;
	
	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

int	validate_var(char *var)
{
	int	i;

	i = 0;
	if (!var || (var[i] != '_' && !ft_isalpha(var[i])))
		return (0);
	while (++i)
	{
		if (var[i] != '_' && !ft_isalnum(var[i]))
			return (0);
	}
	return (i);
}

int	check_if_var_is_in_env(char *arg)
{
	int	i;
	int	len;
	
	i = 0;
	len = ft_strlen(arg);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], arg, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_print_export(t_bt *shell)
{
	
}

void	sort_export(t_bt shell)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	temp = envp;
	while (temp[++i] != NULL)
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
	return (new_export);
}

int	ft_export(char **args, t_bt *shell)
{
	if (ft_strncmp(args[0], "export", 7) == 0)
		ft_print_export(shell);
	else
	{
		if (check_for_value(args[1]))
			ft_add_var(args[1], shell);
		else
			
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:37 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/19 00:31:29 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/* Checking for Arguments
If args[1] == NULL, list all exported variables.

Adding or Updating an Environment Variable
1. Parse VAR=VALUE format.
2. Validate the variable name.
3. Check if it already exists in envp.
4. If it exists, update it.
5. If not, add it to the list. */

int	ft_export(char **args, t_shell *shell)
{
	int		i;
	return (0);
}

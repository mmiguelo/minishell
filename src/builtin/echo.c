/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:19:50 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 13:46:28 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Checks if the given argument is the string "-n".
 * 
 * This function checks if the provided argument `arg` starts with a minus sign
 * (`-`) and is followed only by the letter 'n'. If the argument matches the 
 * pattern `"-n"` (with no additional characters after the 'n'), the function 
 * returns `1`. Otherwise, it returns `0`.
 * 
 * @param arg The argument string to check.
 * @return int Returns 1 if the argument is "-n", 0 otherwise.
 */
static int	ft_is_n(char *arg)
{
	int	i;

	i = -1;
	if (arg[++i] != '-')
		return (0);
	if (!arg[++i])
		return (0);
	while (arg[++i])
	{
		if (arg[i] != 'n')
			return (0);
	}
	return (1);
}

int	ft_echo(char **args, t_bt *shell)
{
	int	i;
	int	n_flag;

	(void)shell;
	i = 1;
	n_flag = 0;
	while (args[i] && ft_is_n(args[i]))
	{
		n_flag = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!n_flag)
		ft_putstr_fd("\n", 1);
	return (0);
}

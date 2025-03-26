/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:20:13 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 14:00:28 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_pwd(char *arg)
{
	if (ft_strcmp(arg, ">") == 0 || ft_strcmp (arg, ">>") == 0
		|| ft_strcmp(arg, "|") == 0)
	{
		ft_printf("pipe or redirect\n");
		return (1);
	}
	return (0);
}

/**
 * @brief Prints the current working directory to the standard output.
 * 
 * This function retrieves and prints the current working directory using the 
 * `getcwd` function. If an argument is provided to the command, it checks if 
 * the argument is valid and returns an error if necessary. If the current 
 * working directory cannot be retrieved, it prints an error message and returns a failure code.
 * 
 * @param args An array of strings containing the arguments passed to the `pwd` command.
 *              The first element (`args[0]`) is the command name (`pwd`), and any subsequent 
 *              elements are options or arguments.
 * @param shell Pointer to the shell structure, containing necessary data for the shell execution.
 * @return int Returns `0` if the current directory is successfully retrieved and printed. 
 *              If an error occurs (such as an invalid argument or failure to get the current directory), 
 *              it prints an error message and returns `1`.
 */
int	ft_pwd(char **args, t_bt *shell)
{
	char	cwd[4096];

	(void)shell;
	if (args[1] && parse_pwd(args[1]))
		return (1);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_printf("%s\n", cwd);
		return (0);
	}
	else
	{
		//TODO: implementar o return code para 1
		ft_printf("pwd: error retrieving current directory\n");
		return (1);
	}
}

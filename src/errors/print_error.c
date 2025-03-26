/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:14:30 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/26 14:40:29 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_msg_error(char *error)
{
	int	status_code;

	status_code = 0;
	if (errno)
		perror(error);
/* 	else
		status_code = ft_print_buffered_error(error); */
	return (status_code);
}

/**
 * @brief 
 * 
 * @param arg 
 * @return int 
 */
int	export_error(char *arg)
{
	if (arg[0] == '-')
	{
		if (arg[1])
			return (ft_printf("minishell: export -%c: invalid option\n",
					arg[1]), 2);
		return (ft_printf("minishell: export: `%s': not a valid identifier\n",
				arg), 1);
	}
	return (0);
}

/**
 * @brief Prints an error message indicating that the provided variable name is
 * not a valid identifier.
 * 
 * This function is used to print an error message when an invalid variable name
 * is encountered during the export process. The error message indicates that the
 * variable is not a valid identifier as per the shell's requirements.
 * 
 * @param var The name of the variable that is not valid.
 */
void	print_invalid_var(char *var)
{
	ft_printf("minishell: export: `%s': not a valid identifier\n", var);
}

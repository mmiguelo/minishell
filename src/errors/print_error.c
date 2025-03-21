/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:14:30 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/21 16:02:55 by mmiguelo         ###   ########.fr       */
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

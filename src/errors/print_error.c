/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:14:30 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/18 19:24:35 by mmiguelo         ###   ########.fr       */
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

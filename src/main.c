/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:19:11 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/25 12:27:46 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void) sig;
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

void	ft_minishell(t_bt *shell, char **envp)
{
	t_builtin	func;
	char		*token;
	char		*input;
	char		*args[100];
	int			i;

	ft_init(shell, envp);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		add_history(input);
		i = 0;
		token = strtok(input, " ");
		while (token && i < 99)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		func = ft_isbuiltin(args[0], shell);
		if (func)
		{
			if (func(args, shell) != 0)
				printf("Error executing %s\n", args[0]);
		}
		else
			printf("Command not found\n");
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_bt	shell;

	(void)argc;
	(void)argv;
	ft_signals();
	ft_memset(&shell, 0, sizeof(t_bt));
	ft_minishell(&shell, envp);
	return (0);
}

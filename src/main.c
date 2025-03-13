/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:19:11 by mmiguelo          #+#    #+#             */
/*   Updated: 2025/03/13 13:03:46 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	sigint_handler(int sig)
{
	(void) sig;
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int main(int argc, char **argv, char **envp)
{
    char input[100];
    char *args[10];  // Allow multiple arguments
    t_builtin func;
    char *token;

    (void)argc;
    (void)argv;

    signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
    while (1)
    {
        printf("minishell> ");
        if (!fgets(input, sizeof(input), stdin))
            break;

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Tokenize input to separate command and arguments
        int i = 0;
        token = strtok(input, " "); // Split input by spaces
        while (token && i < 9) 
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // Null-terminate args list

        // Check if it's a builtin command
        func = ft_isbuiltin(args[0]); 
        if (func)
        {
            if (func(args, &envp) != 0) // Execute builtin
                printf("Error executing %s\n", args[0]);
        }
        else
            printf("Command not found\n");
    }
    return (0);
}

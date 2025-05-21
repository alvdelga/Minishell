/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:41:02 by alvdelga          #+#    #+#             */
/*   Updated: 2025/05/14 09:55:27 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

int main(void) {
    char *input;

    while (1) {
        input = readline("minishell> ");
        if (!input)
            break;
        if (*input)
            add_history(input);

        char **args = parse_input(input);
        if (args && args[0]) {
            if (strcmp(args[0], "exit") == 0)
                break;
            else if (strcmp(args[0], "cd") == 0)
                ft_cd(args);
            else
                execute_command(args);
        }
        free_args(args);
        free(input);
    }
    return 0;
}

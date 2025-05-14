/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:42:01 by alvdelga          #+#    #+#             */
/*   Updated: 2025/05/14 11:58:03 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../minishell.h"

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int count_args(const char *input) {
    int count = 0;
    int in_word = 0;
    int i = 0;

    while (input[i]) {
        if (ft_isspace(input[i])) {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
            if (input[i] == '\'' || input[i] == '\"') {
                char quote = input[i++];
                while (input[i] && input[i] != quote)
                    i++;
            }
        }
        i++;
    }
    return count;
}

static char *extract_token(const char *input, int *index) {
    while (ft_isspace(input[*index]))
        (*index)++;

    int start = *index;
    char quote = 0;

    if (input[*index] == '\'' || input[*index] == '\"') {
        quote = input[(*index)++];
        start = *index;
        while (input[*index] && input[*index] != quote)
            (*index)++;
    } else {
        while (input[*index] && !ft_isspace(input[*index]))
            (*index)++;
    }

    int end = *index;
    if (quote && input[*index] == quote)
        (*index)++;

    char *token = malloc(end - start + 1);
    strncpy(token, &input[start], end - start);
    token[end - start] = '\0';

    return token;
}

char **parse_input(char *input) {
    int i = 0, j = 0;
    int num_args = count_args(input);
    char **args = malloc(sizeof(char *) * (num_args + 1));

    while (input[i]) {
        if (!ft_isspace(input[i])) {
            args[j++] = extract_token(input, &i);
        } else {
            i++;
        }
    }
    args[j] = NULL;
    return args;
}

void free_args(char **args) {
    for (int i = 0; args[i]; i++)
        free(args[i]);
    free(args);
}

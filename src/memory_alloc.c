/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <julthoma@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 03:58:37 by julthoma          #+#    #+#             */
/*   Updated: 2024/07/17 02:59:16 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Alloc term structure
 *
 * @param t_minishell *minishell
 * @return int 0 on success, 1 on failure
 */
static int	alloc_term(t_minishell *minishell)
{
	minishell->term = calloc(1, sizeof(t_term));
	if (!minishell->term)
	{
		free(minishell);
		return (1);
	}
	get_terminal_size(minishell->term);
	minishell->term->cols = PROMPT_LEN + 1;
	minishell->term->rows = 0;
	minishell->term->begin_rows = 0;
	return (0);
}



/**
 * @brief Init minishell structure
 *
 * @return t_minishell *
 */
t_minishell	*alloc_minishell(void)
{
	t_minishell	*minishell;

	minishell = calloc(1, sizeof(t_minishell));
	if (!minishell)
		return (NULL);
	if (alloc_term(minishell))
		return (NULL);
	minishell->input = calloc(1, sizeof(char *));
	if (minishell->input == NULL)
		return (NULL);
	return (minishell);
}

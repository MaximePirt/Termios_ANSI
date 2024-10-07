/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:20:34 by julthoma          #+#    #+#             */
/*   Updated: 2024/10/06 05:36:19 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "minishell.h"

// ########################################################
// #						TERMINAL					  #
// ########################################################

typedef struct s_term
{
	char			*iterm_buffer;
	char			*strterm_buffer;
	unsigned int	ws_cols;
	unsigned int	ws_rows;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	begin_rows;
	struct termios	*original_termios;
}		t_term;

// ########################################################
// #						MINISHELL					  #
// ########################################################

typedef struct s_cache
{
	char			**input;
}		t_cache;

typedef struct s_minishell
{
	t_term			*term;
    char            **input;
}		t_minishell;

#endif

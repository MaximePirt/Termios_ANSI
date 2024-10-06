/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:24:00 by julthoma          #+#    #+#             */
/*   Updated: 2024/10/06 05:45:48 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
#define MAX_32_BIT 4294967295

// ########################################################
// #						LIBFT						  #
// ########################################################

// ########################################################
// #						MINISHELL					  #
// ########################################################

// # include "commands.h"
// # include "config.h"
// # include "debug.h"
// # include "environment.h"
// # include "execution.h"
// # include "history.h"
// # include "memory.h"
// # include "parsing.h"
# include "struct.h"
// # include "terminal.h"
// # include "completion.h"

// ########################################################
// #						DEFAULTS					  #
// ########################################################

//# include <readline/readline.h> BOUH LA HONTE CE TRUC AAAAAAHHHHHHHHHHHHHHHHHHHHHHH !! BURK LES ~400 LEAKS !!!
# include <dirent.h>
# include <fcntl.h>
# include <ncurses.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <term.h>
# include <unistd.h>
#include <ctype.h>

void	get_cursor_position(t_term *term);
void	get_terminal_size(t_term *term);

t_minishell	*alloc_minishell(void);

#endif

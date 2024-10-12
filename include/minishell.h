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

#include "../libft/include/libft.h"
#include "struct.h"
#include "utils.h"


#define PROMPT_LEN 12
#define PROMPT "\033[1;32mminishell$> \033[0m"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
#define MAX_32_BIT 4294967295

// Fonctions pour déplacer le curseur
#define ANSI_UP "\033[A"
#define ANSI_DOWN "\033[B"
#define ANSI_RIGHT "\033[C"
#define ANSI_LEFT "\033[D"

# define CURSOR_UP "\033[%dA"
# define CURSOR_DOWN "\033[%dB"
# define CURSOR_LEFT "\033[%dD"
# define CURSOR_RIGHT "\033[%dC"
# define CURSOR_NLINE "\033[E"
# define CURSOR_PLINE "\033[F]"
# define CURSOR_ERA "\033[2K"

# define L_ARROW 'D'
# define R_ARROW 'C'
# define U_ARROW 'A'
# define D_ARROW 'B'

# define CTRL_D 4
# define CTRL_C 3

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

//
void put_in_string(t_minishell *minishell, char *new);

#endif

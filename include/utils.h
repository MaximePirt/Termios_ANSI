#ifndef UTILS_H
# define UTILS_H

#include "minishell.h"

void move_cursor_left(t_minishell *minishell);
void move_cursor_right(t_term *term);
void move_cursor_up(t_term *term);
void move_cursor_down(t_term *term);


#endif
# include "minishell.h"

void move_cursor_left(t_minishell *minishell)
{
  t_term *term = minishell->term;

    if (term->rows - term->begin_rows == 0 && term->cols <= PROMPT_LEN)
        return ;
    else if (term->rows - term->begin_rows != 0 && term->cols == 0)
      return;


}

void move_cursor_right(t_term *term)
{
    (void) term;
}

void move_cursor_up(t_term *term)
{
    (void) term;

}

void move_cursor_down(t_term *term)
{
    (void) term;

}
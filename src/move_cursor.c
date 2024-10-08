# include "minishell.h"

void move_cursor_left(t_minishell *minishell)
{
  t_term *term = minishell->term;

    if (term->rows - term->begin_rows == 0 && term->cols <= PROMPT_LEN + 1)
        return ;
    if (term->rows - term->begin_rows != 0 && term->cols == 0)
      return;
    if (term->rows - term->begin_rows != 0 && term->cols <= 1)
      {
     	ft_putstr_fd("\033[F", 1);
        ft_printf("\033[%dG", term->ws_cols);
        term->cols = term->ws_cols;
        term->rows--;
        return ;
       }
    ft_putstr_fd("\033[D", 1);
	term->cols--;

}

void move_cursor_right(t_minishell *minishell)
{
  t_term *term = minishell->term;
  size_t	input_len = ft_tablen((const char **)minishell->input);

  if (term->rows - term->begin_rows == 0 && term->cols - PROMPT_LEN >= input_len + 1)
	return ;
  else if (term->rows - term->begin_rows != 0 && term->cols >= ((input_len + PROMPT_LEN) % term->ws_cols + 1))
	return ;
  if (term->cols >= term->ws_cols)
	{
	  ft_putstr_fd("\033[1@\n\033[E", 1);
	  term->cols = 1;
	  term->rows++;
	  return ;
	}
	ft_putstr_fd("\033[C", 1);
	term->cols++;
}

void move_cursor_up(t_minishell *minishell)
{
    (void) minishell;

}

void move_cursor_down(t_minishell *minishell)
{
    (void) minishell;

}
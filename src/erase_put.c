#include "minishell.h"

//static void	backspace_action(t_minishell *minishell)
//{
//    size_t	len;
//
//    len = ft_tablen((const char **)minishell->input);
//    if (minishell->term->cols != minishell->term->ws_cols
//        && minishell->term->cols % minishell->term->ws_cols == 1
//        && minishell->term->begin_rows > 0)
//    {
//        ft_tabdel(minishell->input, len - 1);
//        erase_term(0);
//        minishell->term->cols--;
//        move_cursor_forward(1);
//    }
//    else if (len > 0 && minishell->term->cols != get_prompt_len(minishell) + 1)
//    {
//        erase_in_string(minishell);
//        minishell->term->cols--;
//    }
//}
//
//void	erase_in_string(t_minishell *minishell)
//{
//    char			*res;
//    unsigned int	cols;
//
//    cols = minishell->term->cols;
//    if (cols <= get_prompt_len(minishell))
//        return ;
//    ft_putstr_fd("\033[s", 1);
//    ft_tabdel(minishell->input,
//        (unsigned int)cols - get_prompt_len(minishell) - 2);
//    reset_stdin(minishell);
//    res = ft_utf8_tab_to_str(minishell->input);
//    terminal_print(res, 0, STDOUT_FILENO);
//    free(res);
//    ft_putstr_fd("\033[u", 1);
//    if (cols > get_prompt_len(minishell) + 1)
//        ft_putstr_fd("\033[1D", 1);
//}
//
//
//void	erase_term(size_t len)
//{
//    size_t		i;
//
//    i = 0;
//    while (i < len)
//    {
//        ft_printf(CURSOR_LEFT, 1);
//        i++;
//    }
//    ft_putchar_fd(' ', 1);
//}

#include "minishell.h"

//int	interpret_escape_sequence(t_minishell *minishell, const char *seq)
//{
//    t_history	*new_history;
//
//    if (seq[1] == '[')
//    {
//        new_history = NULL;
//        if (seq[2] == U_ARROW)
//            arrow_up_action(minishell, new_history);
//        else if (seq[2] == D_ARROW)
//            arrow_down_action(minishell, new_history);
//        else if (seq[2] == R_ARROW && minishell->term->cols
//            < ft_tablen((const char **)minishell->input)
//            + get_prompt_len(minishell) + 1)
//            arrow_right_action(minishell);
//        else if (seq[2] == L_ARROW && minishell->term->cols
//            > get_prompt_len(minishell) + 1)
//            arrow_left_action(minishell);
//        return (1);
//    }
//    return (0);
//}
//
//void	reset_stdin(t_minishell *minishell)
//{
//    ft_putstr_fd("\033[2K", 1);
//    move_cursor_back(minishell->term->cols);
//    print_terminal_prompt(minishell, 0);
//}
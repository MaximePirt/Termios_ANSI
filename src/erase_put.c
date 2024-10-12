/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:52:00 by mpierrot          #+#    #+#             */
/*   Updated: 2024/10/11 23:51:50 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*		ft_printf("\033[s\033[4h%s\033[4l\033[0m", new);
*		minishell->input = ft_tabinsert(minishell->input, new,
*			minishell->term->cols - get_prompt_len(minishell) - 1);
*/
//void put_in_string(t_minishell *minishell, char *new)
//{
//    ft_printf("\033[s\033[4h%s\033[4l\033[0m", new);
//    		minishell->input = ft_tabinsert(minishell->input, new,
//    			minishell->term->cols - PROMPT_LEN - 1);
//    return ;
//}

void clear_term(t_minishell *minishell)
{
  unsigned int rows;

    rows = minishell->term->rows;
	while (rows > minishell->term->begin_rows)
		{
			ft_putstr_fd("\033[K\033[1A", 1);
			rows--;
		}
//	ft_putstr_fd("\033[K\033[1A", 1);
    ft_putstr_fd("\033[K", 1);
//    ft_putstr_fd(PROMPT, 1);
//   	printf("\033[%u;%uH", minishell->term->rows, minishell->term->cols);

}

void put_in_string(t_minishell *minishell, char *new)
{
    unsigned int current_cols;
    unsigned int current_rows;

    current_cols = minishell->term->cols;
    current_rows = minishell->term->rows;

    ft_putstr_fd("\033[s", 1);
    if (current_rows - minishell->term->begin_rows == 0)
	{
		minishell->input = ft_tabinsert(minishell->input, new,
			minishell->term->cols - PROMPT_LEN - 1);
        clear_term(minishell);
		ft_putstr_fd(ft_utf8_tab_to_str(minishell->input) + (minishell->term->cols - PROMPT_LEN - 1), STDOUT_FILENO);
	}
    else
    {
        minishell->input = ft_tabinsert(minishell->input, new,
            (current_rows * minishell->term->ws_cols - 1) - PROMPT_LEN + current_cols -1);
        ft_putstr_fd("\033[J", 1);
		ft_putstr_fd(ft_utf8_tab_to_str(minishell->input) + (current_rows * minishell->term->ws_cols - 1) - PROMPT_LEN + current_cols -1, STDOUT_FILENO);
    }
	ft_putstr_fd("\033[u\033[1C", 1);
}

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

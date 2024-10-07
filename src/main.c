#include <termios.h>
#include "minishell.h"
#include "struct.h"
#include <stdio.h>
#include <unistd.h>



void	get_cursor_position(t_term *term)
{
	char			buf[32];
	unsigned int	i;
	int				ret;

	i = 0;
	write(STDOUT_FILENO, "\033[6n", 4);
	while (i < sizeof(buf) - 1)
	{
		ret = read(STDIN_FILENO, buf + i, 1);
		if (ret != 1 || buf[i] == 'R')
			break ;
		i++;
	}
	buf[i] = '\0';
	if (buf[0] == '\033' && buf[1] == '[')
	{
		i = 2;
		term->rows = atoi(buf + i);
		while (buf[i] && isdigit(buf[i]))
			i++;
		term->cols = atoi(buf + i + 1);
	}
}

void	get_terminal_size(t_term *term)
{
	struct winsize	size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	term->ws_rows = size.ws_row;
	term->ws_cols = size.ws_col;
}

// Fonctions pour configurer le terminal et restaurer les paramètres d'origine
void set_raw_mode(struct termios *old_attrs) {
    struct termios new_attrs;
    tcgetattr(STDIN_FILENO, old_attrs);
    new_attrs = *old_attrs;
    new_attrs.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attrs);
}

void reset_terminal_mode(struct termios *old_attrs) {
    tcsetattr(STDIN_FILENO, TCSANOW, old_attrs);
}

int	process_signals(char c)
{
	if (c == CTRL_D)
		return (1);
	else if (c == CTRL_C)
		return (1);
	return (0);
}

void	interpret_escape_sequence(t_minishell *minishell, char *new)
{
	if (new[1] == '[')
	{
		if (new[2] == U_ARROW)
			move_cursor_up(minishell);
		else if (new[2] == D_ARROW)
			move_cursor_down(minishell);
		else if (new[2] == R_ARROW)
			move_cursor_right(minishell);
		else if (new[2] == L_ARROW)
			move_cursor_left(minishell);
	}
}

int process_action(t_minishell *minishell, char *new)
{
	if (new[0] == '\033')
    {
        interpret_escape_sequence(minishell, new);
        return (0);
	}
    else if (strcmp(new, " ") == 0)
    {
    	ft_printf("vla cols : %d\n", minishell->term->rows);
        return (0);
    }
	ft_putstr_fd(new, 1);
	minishell->input = ft_tabjoin(minishell->input,
				ft_utf8_split_chars(new));
    minishell->term->cols++;
    if (minishell->term->cols >= minishell->term->ws_cols)
	{
		minishell->term->cols = 1;
		minishell->term->rows++;
	}
	minishell->term->rows = (ft_tablen((const char **)minishell->input) + PROMPT_LEN)
		/ minishell->term->ws_cols + minishell->term->begin_rows;
	return (0);
}

// Programme principal
int main() {
    struct termios old_attrs;
	ssize_t bits;
	char buffer[32];
	t_minishell *minishell;
	int signal;

	minishell = alloc_minishell();
    // Configuration du mode raw pour la saisie clavier
    set_raw_mode(&old_attrs);

    ft_putstr_fd("1234567891234 :", 1);
    while (1) {
		get_terminal_size(minishell->term);
		bits = read(STDIN_FILENO, &buffer, sizeof(buffer));
		if (bits == -1)
		{
			perror("read");
			return (0);
		}

		buffer[bits] = '\0';
		signal = process_signals(buffer[0]);
		if (signal)
			break ;
		if (process_action(minishell, buffer))
			break;
    }
	printf("OUT");

    // Restauration des paramètres du terminal
    reset_terminal_mode(&old_attrs);
    return 0;
}

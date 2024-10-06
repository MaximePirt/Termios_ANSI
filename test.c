#include <termios.h>
#include "minishell.h"
#include "struct.h"
#include <stdio.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

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

void move_cursor(const char *direction) {
    printf("%s", direction);
    fflush(stdout);
}

int	process_signals(char c)
{
	if (c == CTRL_D)
	{
		return (1);
	}
	else if (c == CTRL_C)
	{
		return (1);
	}
	return (0);
}

int process_action(t_minishell *minishell, char *new)
{
	printf("ahahah");
	return (0);
}

// Programme principal
int main() {
    struct termios old_attrs;
	ssize_t bits;
	char buffer[32];
    char key;
	t_minishell *minishell;
	int signal;

	minishell = alloc_minishell();
    // Configuration du mode raw pour la saisie clavier
    set_raw_mode(&old_attrs);

    printf("Programme lancer\n");
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

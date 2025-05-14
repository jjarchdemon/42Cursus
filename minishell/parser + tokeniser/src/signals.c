#include "minishell.h"

static void handle_sigint(int sig);

// Setup signal handlers
// for SIGINT (ctrl-C) and SIGQUIT (ctrl-\)
void setup_signals(void)
{
	struct sigaction sa_int;
	struct sigaction sa_quit;

	sa_int.sa_handler = handle_sigint;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = SIG_IGN; 
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = 0;
	sigaction(SIGQUIT, &sa_quit, NULL);
}

// Signal handler for SIGINT (ctrl-C)
static void handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);		// Move to a new line
	rl_on_new_line();		// Inform readline that a new line is starting
	rl_replace_line("", 0);	// Clear the current input line
	rl_redisplay();			// Redisplay the prompt
}

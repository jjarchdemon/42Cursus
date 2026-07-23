#include <stdlib.h>
#include <unistd.h>

int ft_popen (const char *file, char *const argv[], char type)
{
	int		fds [2];
	pid_t	pid;

	if (!file || !argv || (type != 'r' && type !='w'))
		return -1;

	if (pipe(fds) == -1)
		return -1;

	pid = fork();
	if (pid = -1)
	{
		close (fds[0]);
		close (fds [1]);
		return -1;
	}
	
	if (pid == 0)
	{
		// the child process must redirect its Standard Output (STDOUT_FILENO) into the write-end of the pipe (fds[1])
		if (type =='r')
		{
			if (dup2 (fds[0], STDIN_FILENO) == -1) // WRONG: Connected read-end to STDIN
				exit (1);
		}
		// the child process must redirect the read-end of the pipe (fds[0]) into its Standard Input (STDIN_FILENO)
		if (type == 'w')
		{
			if (dup2(fds[1], STDOUT_FILENO) == -1) // WRONG: Connected write-end to STDOUT
				exit (1);
		}
		close(fds[0]) ;
		close(fds[1]) ;

		execvp(file, argv);
		exit(1) ;
	}
	
	if(type == 'r')
	{
		close(fds[1]);
		return fds[0];
	}
	if(type == 'w')
	{
		close (fds[0]);
		return fds[1];
	}
	return 0;
}

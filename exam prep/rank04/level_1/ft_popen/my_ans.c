#include <unistd.h> //STDIN_FILENO, pipe, fork, close, exec
#include <stdlib.h> // exit


/* pseudocode
 *
 * error 1: wrong args
 * error 2: pipe fail
 * error 3: fork fail
 *
 * in child:
 * if type = r, connect write end to stdout
 * if type = w, connect read  end to stdin
 * close both pipe ends
 * replace the child process with file using execvp
 *
 * in parent: 
 * if type = r, return read  end of pipe
 * if type = w, return write end of pipe
 *
*/


//3 error checks
//child process, 2 conditions + exec
//parent process, 2 conditions


int ft_popen(const char *file, char *const argv[], char type)
{
	int fds[2];
	pid_t pid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;
	if (pipe(fds)== -1)
		return -1;
	pid = fork();
	if (pid == -1)
	{
		close(fds[0]);
		close(fds[1]);
		return(-1);
	}
	
	if (pid == 0)
	{
		if (type == 'r')
		{
			if (dup2(fds[1],STDOUT_FILENO)== -1)
				exit(1);
		}
		if (type == 'w')
		{
			if (dup2(fds[0], STDIN_FILENO) == -1)
				exit(1);
		}
		close(fds[0]);
		close(fds[1]);
		execvp(file, argv);
		exit(1);
	}
	if (type == 'r')
	{
		close(fds[1]);
		return fds[0];
	}
	else
	{
		close(fds[0]);
		return fds[1];
	}

}















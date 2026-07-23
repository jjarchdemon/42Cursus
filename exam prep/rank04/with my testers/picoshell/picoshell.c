/*
 * 0. keep track of prev pipe
 *
 * for each command:
 * 1. set up pipe (if not last command)
 * 2. fork
 * 3. child process:
 *		- hook up input (from previous command)
 *		- hook up output (to next command)
 *		- execute command
 * 4. parent process:
 *		- close old read end
 *		- setup variables for next loop iteration
 *
 * 5. wait for all children
 * 6. return success
 *
*/

//		input output execvp
// pf ioe ccs
//			close prevfd|close write|save read in prevfd
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
	int i = 0;
	int prev_fd = -1;
	pid_t pid;
	int fds[2];

	//pipe fork
	
	while (cmds[i])
	{
		if (cmds[i+1] && pipe(fds))
			return 1;
		pid = fork();
		if (pid == -1)
		{
			if (cmds[i+1])
			{
				close(fds[0]);
				close(fds[1]);
				return 1;
			}
		}

		if (pid == 0)
		{
			if(prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) == -1)
					exit(1);
				close(prev_fd);
			}
			if(cmds[i+1])
			{
				close(fds[0]);
				if (dup2(fds[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fds[1]);
			}
			execvp(cmds[i][0], cmds[i]);	//TODO cmds[i][0]
			exit(1);
		}

		if (prev_fd != -1)
			close(prev_fd); //TODO return 1 as well| was correct

		if (cmds[i+1])
		{
			close(fds[1]);
			prev_fd = fds[0];
			//return prev_fd;		//TODO wrong
		}
		i++;
	}
	while(wait(NULL) > 0);
	return 0;
}

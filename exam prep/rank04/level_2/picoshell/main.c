#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int picoshell(char **cmds[]);

int main(int argc, char **argv)
{
	//initialise count of commands
	int cmds_size = 1;
	
	//every | denotes a command following it
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
			cmds_size++;
	}
	
	//allocate memory
	char ***cmds = calloc(cmds_size + 1, sizeof(char **));
	if (!cmds)
	{
		dprintf(2, "Malloc error: %m\n");
		return 1;
	}
	
	//parsing & splitting the commands
	cmds[0] = argv + 1;
	int cmds_i = 1;
	for (int i = 1; i < argc; i++)
		if (!strcmp(argv[i], "|"))
		{
			cmds[cmds_i] = argv + i + 1;
			argv[i] = NULL;
			cmds_i++;
		}
		
	//calling picoshell
	int ret = picoshell(cmds);
	if (ret)
		perror("picoshell");
	free(cmds);
	return ret;
}
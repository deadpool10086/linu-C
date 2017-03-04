#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int status;
	pid_t pc,pr;
	if((pc = fork()) == -1)
	{
		printf("faild to create a new process\n");
		exit(0);
	}
	else if(pc == 0)
	{
		printf("This is child process with pid of %d.\n",getpid());
		exit(3);
	}
	else
	{
		pr = wait(&status);
		if(WIFEXITED(status))
		{
			printf("the child process %d exit normally.\n",pr);
			printf("the return code is %d.\n",WEXITSTATUS(status));
		}
		else
		{
			printf("the child process %d exit abnormally.\n",pr);	
		}
	}
	return 0;

	return 0;	
}


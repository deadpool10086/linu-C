#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pc,pr;
	if((pc = fork()) < 0)
	{
		printf("erron in fork!\n");
		exit(1);
	}
	else if(pc == 0)
	{
		printf("This is child process with pid ios %d\n",getpid());
		sleep(10);
	}
	else
	{
		pr = wait(NULL);
		printf("I catched a child process with pid os %d\n",pr);
	}
	exit(0);
//	return 0;
}

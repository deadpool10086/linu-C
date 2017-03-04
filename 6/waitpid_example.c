#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pc,pr;
	if((pc = fork()) == -1)
	{
		printf("faild to create a new process\n");
		exit(0);
	}
	else if(pc == 0)
	{
		sleep(10);	
		exit(0);
	}
	do
	{
		pr = waitpid(pc,NULL, WNOHANG);
		if(pr == 0)
		{
			printf("No child exited\n");
			sleep(1);
		}
	}while(pr == 0);
	if(pr == pc)
	{
		printf("successfully get child %d\n",pr);	
	}
	else
	{
		printf("some error occured\n");	
	}
	return 0;	
}

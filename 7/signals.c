#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sigroutine(int dumnno)
{
	switch(dumnno)
	{
		case 1:printf("Capture SIGHUP signal,the signal number is %d\n",dumnno);	
		case 2:printf("Capture SIGINT signal,the signal number is %d\n",dumnno);	
		case 3:printf("Capture SIGQUT signal,the signal number is %d\n",dumnno);	
	}
	return;
}

int main(void)
{
	printf("process ID is %d\n",getpid());
	if(signal(SIGHUP,sigroutine) == SIG_ERR)
	{
		printf("Couldn't register signal handle for SIGHUP!\n");	
	}
	if(signal(SIGINT,sigroutine) == SIG_ERR)
	{
		printf("Couldn't register signal handle for SIGHUP!\n");	
	}
	if(signal(SIGQUIT,sigroutine) == SIG_ERR)
	{
		printf("Couldn't register signal handle for SIGHUP!\n");	
	}
	while(1)
		sleep(1);
	return 0;	
}

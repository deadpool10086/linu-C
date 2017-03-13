#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	signal(SIGINT,SIG_DFL);
	while(1)
		sleep(1);
	return 0;	
}



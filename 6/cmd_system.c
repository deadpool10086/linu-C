#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int status;
	if((status=system(NULL)) < 0)
	{
		printf("system error!\n");
		exit(0);
	}
	printf("exit status=%d\n",status);
	
	if((status=system("date")) < 0)
	{
		printf("system error!\n");
		exit(0);
	}
	printf("exit status=%d\n",status);
	
	if((status=system("invalidcommand")) < 0)
	{
		printf("system error!\n");
		exit(0);
	}
	printf("exit status=%d\n",status);

	if((status=system("who;exit 44")) < 0)
	{
		printf("system error!\n");
		exit(0);
	}
	printf("exit status=%d\n",status);

	return 0;	
}

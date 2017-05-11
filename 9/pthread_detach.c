#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *threaddeal(void * arg)
{
	int i = *(int*)(arg);
	printf("this is NO:%d thread\n",i);	
}

int main(void)
{
	pthread_t threadid;
	int j;
	int count = 20;
	for(j=0; j < count; j++)
	{
		int * p = &(j);	
		int ret = pthread_create(&threadid, NULL, threaddeal,(void*)p);
		if(ret)
		{
			printf("create thread faild:%d\n",ret);
		}
		else
		{
			pthread_detach(threadid);
		}
	}
	sleep(3);
	return 0;	
}

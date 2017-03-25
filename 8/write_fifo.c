#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define BUFES PIPE_BUF

int main(void)
{
	int fd;
	int n, i;
	char buf[BUFES];
	time_t tp;
	printf("I am %d\n",getpid());

	if( (fd = open("fifo1",O_WRONLY)) < 0 )
	{
		printf("Open failed!\n");
		exit(0);
	}

	for( i=0; i<10; i++)
	{
		time(&tp);
		n = sprintf(buf,"write_fifo %d  sends %s", getpid(), (char *)ctime(&tp));
		printf("Send msg:%s",buf);
		if((write(fd, buf, n+1)) < 0 )
		{
			printf("Write failed!\n");	
			close(fd);
			exit(1);
		}
		sleep(3);
	}
	close(fd);
	return 0;	
}

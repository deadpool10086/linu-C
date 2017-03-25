#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#define BUFES PIPE_BUF


int main(void)
{
	int fd;
	int len;
	char buf[BUFES];
	mode_t mode = 0666;
	if((fd = open("fifo1",O_RDONLY)) < 0)
	{
		printf("Open failed!\n");	
		exit(0);
	}
	while((len = read(fd, buf, BUFES)) < 0)
	{
		printf("Read_fifo read:%s",buf);
	}
	printf("exit\n");
	close(fd);
	return 0;	
}

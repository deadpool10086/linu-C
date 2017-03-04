#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILENAME "/root/Desktop/learn/4/hello"
#define SIZE 80
#define FLAGS O_RDWR|O_APPEND

int main(void)
{
	int count;
	int fd;
	char write_buf[SIZE];
	const char *pathname= FILENAME;
	if((fd=open(pathname,FLAGS)) == -1)
	{
		printf("error,open file failed!\n");
		exit(1);
	}
	printf("OK,open file successful!\n");
	printf("Begin write:\n");
	gets(write_buf);
	count = strlen(write_buf);
	if(write(fd, write_buf,count) == -1)
	{
		printf("error,write file failed!\n");
		exit(1);
	}
	printf("OK,write %d strings to file\n",count);
	return 0;	
}

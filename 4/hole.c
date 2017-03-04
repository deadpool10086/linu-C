#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILENAME "/root/Desktop/learn/4/test"
#define FLAGS O_WRONLY|O_CREAT|O_TRUNC
#define MODE 0600

int main(void)
{
	char buf1[] = {"abcdefghij"};
	char buf2[] = {"1234567890"};
	int fd;
	int count;
	const char *pathname = FILENAME;
	if((fd = open(pathname, FLAGS, MODE)) == -1)
	{
		printf("error,open file faild!\n");
		exit(1);
	}
	count = strlen(buf1);
	if(write(fd,buf1,count) != count)
	{
		printf("error,write file faild!\n");	
		exit(1);
	}
	if(lseek(fd, 50, SEEK_SET) == -1)
	{
		printf("error,lseek failed!\n");	
		exit(1);
	}
	count = strlen(buf2);
	if(write(fd,buf2,count) != count)
	{
		printf("error, write file failed!\n");
		exit(1);
	}
	return 0;	
}
